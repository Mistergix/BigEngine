//
// Created by nicol on 09/05/2022.
//

#include "game_object.h"
#include "components/transform.h"

#include <utility>

std::vector<GameObject *> GameObject::_allObjects;

GameObject::GameObject() : GameObject("New Game Object"){
}

GameObject::GameObject(std::string name) {
    std::vector<Component *> c;
    Init(std::move(name), c);
}

GameObject::GameObject(std::string name, std::vector<Component *> components) {
    Init(std::move(name), std::move(components));
}

void GameObject::Init(std::string name, std::vector<Component *> components) {
    this->name() = std::move(name);
    _activeSelf = true;
    _isStatic = false;
    _tag = "Untagged";
    ReplaceComponents(std::move(components));
    auto t = GetComponent<Transform>();
    if(!t){
        ADD_COMPONENT(Transform);
    }
    GameObject::RegisterObject(this);
    _started = false;
}

template<typename T>
void GameObject::AddComponent(const std::string& className) {
    T* component = new T();
    AddComponent(component, className);
}

bool GameObject::CompareTag(const std::string& tag) {
    // TODO Hash ?
    return _tag == tag;
}

void GameObject::SetActive(bool active) {
    _activeSelf = active;
}

template<typename T>
T *GameObject::GetComponent() {
    // TODO  Replace vector with map ? because dynamic cast is expensive
    // https://stackoverflow.com/a/55608393
    T* result = nullptr;
    for(Component* comp : _components){
        result = dynamic_cast<T*>(comp);
        if(result){break;}
    }
    return result;
}

const bool &GameObject::activeSelf() const {
    return _activeSelf;
}

bool &GameObject::activeSelf() {
    return _activeSelf;
}

bool &GameObject::isStatic() {
    return _isStatic;
}

const bool &GameObject::isStatic() const {
    return _isStatic;
}

std::string &GameObject::tag() {
    return _tag;
}

const std::string &GameObject::tag() const {
    return _tag;
}

Transform *GameObject::transform() {
    return GetComponent<Transform>();
}

void GameObject::Deserialize(nlohmann::basic_json<> json) {
    Object::Deserialize(json);
    name() = json.at("name");
    tag() = json.at("tag");
    activeSelf() = json.at("active");

    ClearComponents();
    auto jComponents = json.at("components");
    for (const auto& jComponent : jComponents) {
        AddComponentFromSerializedFile(jComponent);
    }
}

void GameObject::AddComponentFromSerializedFile(nlohmann::basic_json<> jComponent) {
    auto className = jComponent.at("class");
    auto component = ComponentFactory::CreateInstance(className);
    component->Deserialize(jComponent);
    AddComponent(component, className);
}

void GameObject::ReplaceComponents(std::vector<Component *> components) {
    ClearComponents();
    _components = std::move(components);
}

void GameObject::AddComponent(Component* component, const std::string& className) {
    _components.push_back(component);
    component->SetGameObject(this);
    GameObject::RegisterComponent(component, className, this);
}


void GameObject::RegisterComponent(Component *pComponent, const std::string& className, GameObject *pObject) {
    ComponentTable::RegisterComponent(pComponent, className);
}

void GameObject::ClearComponents() {
    for (auto component : _components) {
        ComponentTable::UnregisterComponent(component);
        delete component;
    }

    _components.clear();
}

std::vector<GameObject *> *GameObject::FindObjectsOfType(const std::string& className) {
    auto components = ComponentTable::FindAllComponents(className);
    auto* go = new std::vector<GameObject*>;
    for (auto c : *components) {
        go->push_back(c->gameObject());
    }
    return go;
}

std::vector<GameObject *> *GameObject::FindObjectsWithTag(const std::string &tag) {
    auto* gos = new std::vector<GameObject*>;
    for (auto go : _allObjects) {
        if(go->CompareTag(tag)){
            gos->push_back(go);
        }
    }
    return gos;
}

void GameObject::RegisterObject(GameObject *pObject) {
    std::cout << "Add " << pObject->name() << " to global list" << std::endl;
    _allObjects.push_back(pObject);
}

void GameObject::OnStart() {
    if(_started){
        return;
    }

    for (auto c : _components) {
        c->OnStart();
    }
    _started = true;
}

void GameObject::PhysicsUpdate(double dt) {
    for (auto c : _components) {
        c->OnPhysicsUpdate(dt);
    }
}

void GameObject::Update(double dt) {
    if(!_started){
        OnStart();
    }

    for (auto c : _components) {
        c->OnUpdate(dt);
    }
}

void GameObject::Destroy(GameObject &object) {
    //TODO lazy delete
    object.ClearComponents();
    object._components.shrink_to_fit();
    GameObject::UnregisterObject(object);
    delete &object;
}

void GameObject::UnregisterObject(GameObject &object) {
    std::cout << "Delete " << object.name() << " to global list" << std::endl;
    auto listIt = std::find(_allObjects.begin(), _allObjects.end(), object);
    _allObjects.erase(listIt);
}

