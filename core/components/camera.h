//
// Created by pouyoupy on 10/05/2022.
//

#ifndef BIG_ENGINE_CAMERA_H
#define BIG_ENGINE_CAMERA_H

#include "../component.h"
#include "../Math/Matrix4.hpp"
#include "Glm/glm.hpp"



class Camera : public Component {

public:

    virtual void Deserialize(nlohmann::basic_json<> json) override;

    enum cameraType { Perspective, Orthographic };
    cameraType type;

    float pitch;
    float yaw;

    float fov;
    float near_clipping;
    float far_clipping;

    Camera();
    void init(float y = 0.0f, float p = 0.0f, cameraType t = cameraType::Perspective, float f = 60, float n = 0.1f, float c = 100.0f);
    glm::mat4 getViewProjection(float aspect_ratio = 1.0f);

private:

    glm::vec3 _direction;
    glm::vec3 _camCenter;
    glm::vec3 _camUp;
    glm::vec3 _camPos;
    glm::vec3 _camFront;

    glm::mat4 _current_MVP;

    glm::mat4 _projection_mat;
    glm::mat4 _view_mat;

    REGISTER_DECLARATION_TYPE(Camera)

};


#endif //BIG_ENGINE_CAMERA_H
