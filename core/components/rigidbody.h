//
// Created by nicol on 11/05/2022.
//

#ifndef BIG_ENGINE_RIGIDBODY_H
#define BIG_ENGINE_RIGIDBODY_H


#include "../component.h"
#include "../../Math/Vector3.hpp"

class RigidBody : Component {
public:
    RigidBody();
    void Deserialize(nlohmann::basic_json<> json) override;
    void OnUpdate(double deltaTime) override;
    void OnPhysicsUpdate(double physicsDeltaTime) override;
private:
    REGISTER_DECLARATION_TYPE(RigidBody)
    float _mass;
    Vector3 _position;
    Vector3 _velocity;
    Vector3 _acceleration;
    Vector3 _momentum;
    bool _init;
};


#endif //BIG_ENGINE_RIGIDBODY_H
