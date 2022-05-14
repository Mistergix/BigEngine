//
// Created by nicol on 09/05/2022.
//

#include "component.h"
#include "game_object.h"

ComponentFactory::map_type * ComponentFactory::_map = nullptr;
ComponentTable::table_type * ComponentTable::_table = nullptr;
std::map<Component*, std::string> ComponentTable::_componentsList;


void Component::OnRelease() {

}

void Component::OnPhysicsUpdate(double physicsDeltaTime) {

}

void Component::OnUpdate(double deltaTime) {

}

void Component::OnStart() {

}

void Component::SetGameObject(GameObject *go) {
    _gameObject = go;
}

GameObject *Component::gameObject() {
    return _gameObject;
}

std::string &Component::name() {
    return gameObject()->name();
}

