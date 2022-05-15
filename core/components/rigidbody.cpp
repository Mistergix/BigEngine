//
// Created by nicol on 11/05/2022.
//

#include "rigidbody.h"
#include "../game_object.h"

REGISTER_DEFINITION_TYPE(RigidBody)

void RigidBody::Deserialize(nlohmann::basic_json<> json) {
    Object::Deserialize(json);
    _mass = json.at("mass");
}

void RigidBody::OnPhysicsUpdate(double physicsDeltaTime) {
    Component::OnPhysicsUpdate(physicsDeltaTime);

    if(!_init){
        _init = true;
        _position = gameObject()->transform()->GetPosition();
    }

    auto mult = (_acceleration / _mass) * (float)physicsDeltaTime;

    _velocity = _velocity + mult;
    _position = _position + _velocity * (float)physicsDeltaTime;
    std::cout << "Velocity of " << name() << " : " << _velocity << std::endl;
    //malek.bengougam@gmail.com
}

void RigidBody::OnUpdate(double deltaTime) {
    Component::OnUpdate(deltaTime);
    gameObject()->transform()->SetPosition(_position);
}

RigidBody::RigidBody() {
    _acceleration = Vector3(0, -9.81f, 0);
    _velocity = Vector3();
    _position = Vector3();
    _mass = 1.0;
    _init = false;
}
