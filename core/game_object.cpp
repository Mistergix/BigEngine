//
// Created by nicol on 09/05/2022.
//

#include "game_object.h"
#include "components/transform.h"

#include <utility>

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
    _components = std::move(components);
    auto t = GetComponent<Transform>();
    if(!t){
        AddComponent<Transform>();
    }
}

template<typename T>
void GameObject::AddComponent() {
    T* component = new T();
    _components.push_back(component);
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
    // Replace vector with map ? because dynamic cast is expensive
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


