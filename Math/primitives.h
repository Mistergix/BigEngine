//
// Created by pouyoupy on 11/05/2022.
//

#ifndef BIG_ENGINE_PRIMITIVES_H
#define BIG_ENGINE_PRIMITIVES_H

#include "Glew/glew.h"


static class Primitives {
public:
    static const GLfloat CUBE_VERT_DATA[24];
    static const GLushort CUBE_ELEMENT_DATA[36];
    static const GLfloat CUBE_UV_DATA[16];
    static const GLushort PLANE_ELEMENT_DATA[6];
    static const GLfloat PLANE_VERT_DATA[20];
} primitives;


#endif //BIG_ENGINE_PRIMITIVES_H
