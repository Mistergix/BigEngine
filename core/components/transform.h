//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_TRANSFORM_H
#define BIG_ENGINE_TRANSFORM_H


#include "../component.h"
#include "../../Math/Matrix4.hpp"
#include "../../Math/Vector3.hpp"

class Transform : public Component{
public:
    virtual void Deserialize(nlohmann::basic_json<> json) override;

    void GetWorldMatrix(Matrix4& world);
    void SetPosition(const  Vector3& position);
    void SetRotation(const  Vector3& rotation);
    void SetScale(const  Vector3& scale);

    Vector3 GetPosition();
    Vector3 GetRotation();
    Vector3 GetScale();
protected:
    Matrix4 m_world;

    Vector3 m_position;
    Vector3 m_rotation;
    Vector3 m_scale = Vector3(1, 1, 1);

    void ProcessWorldMatrix();
private:
    REGISTER_DECLARATION_TYPE(Transform);
};


#endif //BIG_ENGINE_TRANSFORM_H
