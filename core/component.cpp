//
// Created by nicol on 09/05/2022.
//

#include "component.h"

ComponentFactory::map_type * ComponentFactory::_map = nullptr;
ComponentTable::table_type * ComponentTable::_table = nullptr;
std::map<Component*, std::string> ComponentTable::_componentsList;


void Component::OnRelease() {

}

void Component::OnPhysicsUpdate(float physicsDeltaTime) {

}

void Component::OnUpdate(float deltaTime) {

}

void Component::OnCreate() {

}

void Component::SetGameObject(GameObject *go) {
    _gameObject = go;
}

GameObject *Component::gameObject() {
    return _gameObject;
}

