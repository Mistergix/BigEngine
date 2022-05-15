//
// Created by pouyoupy on 10/05/2022.
//

#include "camera.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtc/type_ptr.hpp"

REGISTER_DEFINITION_TYPE(Camera)

void Camera::Deserialize(nlohmann::basic_json<> json) {
    Component::Deserialize(json);
}

Camera::Camera(){
    type = cameraType::Perspective;
    near_clipping = 0.1f;
    far_clipping = 100.0f;
    fov = 60;
    _camUp = glm::vec3(0.0f, 1.0f, 0.0f);
    _camPos = glm::vec3(0.0f, 0.0f, 3.0f);
    _camFront = glm::vec3(0.0f, 0.0f, -1.0f);
}

void Camera::init(float y, float p, cameraType t, float f, float n, float c)
{
    pitch = p;
    yaw = y;

    near_clipping = n;
    far_clipping = c;
    type = t;
    fov = f;
}

glm::mat4 Camera::getViewProjection(float aspect_ratio)
{
    //Find projection matrix
    if (type == cameraType::Perspective) _projection_mat = glm::perspective(glm::radians(fov), (float)aspect_ratio, near_clipping, far_clipping);
    if (type == cameraType::Orthographic) _projection_mat = glm::ortho(-fov, fov, -fov, fov, near_clipping, far_clipping);

    //Convert yaw and pitch to a vector
    glm::vec3 temp_front;

    //Use equation
    temp_front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    temp_front.y = sin(glm::radians(pitch));
    temp_front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

    //Apply to view matrix
    _view_mat = glm::lookAt(_camPos, _camPos + _camFront, _camUp);


    //Done
    _current_MVP = _projection_mat * _view_mat;

    //Return
    return _current_MVP;
};