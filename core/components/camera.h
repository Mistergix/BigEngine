//
// Created by pouyoupy on 10/05/2022.
//

#ifndef BIG_ENGINE_CAMERA_H
#define BIG_ENGINE_CAMERA_H


class camera {

public:

    enum cameraType { Perspective, Orthographic };
    cameraType type;

    float fov;
    float near_clipping;
    float far_clipping;

};


#endif //BIG_ENGINE_CAMERA_H
