//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_GAME_OBJECT_H
#define BIG_ENGINE_GAME_OBJECT_H


#include "object.h"
#include "component.h"
#include "components/transform.h"
#include "../utils/json.hpp"

#define ADD_COMPONENT(NAME) AddComponent<NAME>(#NAME)
#define FIND_OBJECTS_OF_TYPE(NAME) GameObject::FindObjectsOfType(#NAME)


class GameObject : public Object {
public:
    GameObject();
    GameObject(std::string name);
    GameObject(std::string name, std::vector<Component*> components);
    template <typename T>
    void AddComponent(const std::string& className);
    bool CompareTag(const std::string& tag);
    template <typename T>
    T* GetComponent();
    void SetActive(bool active);
    bool& activeSelf();
    [[nodiscard]] const bool& activeSelf() const;
    bool& isStatic();
    [[nodiscard]] const bool& isStatic() const;
    std::string& tag();
    [[nodiscard]] const std::string& tag() const;
    Transform* transform();
    void Deserialize(nlohmann::basic_json<> json) override;
    static std::vector<GameObject*>* FindObjectsOfType(const std::string& className);
    static std::vector<GameObject*>* FindObjectsWithTag(const std::string& tag);
private:
    void Init(std::string name, std::vector<Component*> components);
    void AddComponentFromSerializedFile(nlohmann::basic_json<> json);
    void AddComponent(Component* component, const std::string& className);
    bool _activeSelf;
    bool _isStatic;
    std::string _tag;
    std::vector<Component*> _components;

    static std::vector<GameObject *> _allObjects;

    static void RegisterComponent(Component *pComponent, const std::string& className, GameObject *pObject);

    void ReplaceComponents(std::vector<Component *> vector1);

    void ClearComponents();

    void RegisterObject(GameObject *pObject);
};


#endif //BIG_ENGINE_GAME_OBJECT_H
