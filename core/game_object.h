//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_GAME_OBJECT_H
#define BIG_ENGINE_GAME_OBJECT_H


#include "object.h"
#include "component.h"
#include "components/transform.h"
#include "../utils/json.hpp"


class GameObject : public Object {
public:
    GameObject();
    GameObject(std::string name);
    GameObject(std::string name, std::vector<Component*> components);
    template <typename T>
    void AddComponent();
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
private:
    void Init(std::string name, std::vector<Component*> components);
    void AddComponentFromSerializedFile(nlohmann::basic_json<> json);
    void AddComponent(Component* component);
    bool _activeSelf;
    bool _isStatic;
    std::string _tag;
    std::vector<Component*> _components;
};


#endif //BIG_ENGINE_GAME_OBJECT_H
