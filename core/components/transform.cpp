//
// Created by nicol on 09/05/2022.
//

#include "transform.h"

REGISTER_DEFINITION_TYPE(Transform)

void Transform::Deserialize(nlohmann::basic_json<> json) {
    Component::Deserialize(json);
    SetScale(DeSerializeVector3(json.at("localScale")));
    SetRotation(DeSerializeVector3(json.at("localRotation")));
    SetPosition(DeSerializeVector3(json.at("localPosition")));
}

void Transform::ProcessWorldMatrix() {
    Matrix4 temp;

    m_world.setIdentity();

    temp.setIdentity();
    temp.setScale(m_scale);
    m_world *= temp;


    temp.setIdentity();
    temp.setRotationX(m_rotation.x);
    m_world *= temp;

    temp.setIdentity();
    temp.setRotationY(m_rotation.y);
    m_world *= temp;

    temp.setIdentity();
    temp.setRotationZ(m_rotation.z);
    m_world *= temp;


    temp.setIdentity();
    temp.setTranslation(m_position);
    m_world *= temp;
}

void Transform::SetScale(const Vector3 &scale) {
    m_scale = scale;
    ProcessWorldMatrix();
}

void Transform::GetWorldMatrix(Matrix4 &world) {
    world = m_world;
}

void Transform::SetPosition(const Vector3 &position) {
    m_position = position;
    ProcessWorldMatrix();
}

void Transform::SetRotation(const Vector3 &rotation) {
    m_rotation = rotation;
    ProcessWorldMatrix();
}

Vector3 Transform::GetPosition() {
    return m_position;
}

Vector3 Transform::GetRotation() {
    return m_rotation;
}

Vector3 Transform::GetScale() {
    return m_scale;
}

Vector3 Transform::DeSerializeVector3(nlohmann::basic_json<> jVector3) {
    return {jVector3.at("x"), jVector3.at("y"), jVector3.at("z")};
}

