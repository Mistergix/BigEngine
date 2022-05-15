//
// Created by pouyoupy on 11/05/2022.
//

#include "primitives.h"


const GLfloat Primitives::CUBE_VERT_DATA[24] = {

        -1, -1, -1,
        +1, -1, -1,
        +1, +1, -1,
        -1, +1, -1,


        -1, -1, +1,
        +1, -1, +1,
        +1, +1, +1,
        -1, +1, +1,
};

const GLfloat Primitives::CUBE_UV_DATA[16] = {
        0, 0,
        1, 0,
        1, 1,
        0, 1,

        0, 0,
        1, 0,
        1, 1,
        0, 1
};

const GLushort Primitives::CUBE_ELEMENT_DATA[36] = {

        0, 1, 2,
        0, 2, 3,


        4, 5, 6,
        4, 7, 6,


        5, 6, 2,
        5, 1, 2,


        3, 7, 4,
        3, 0, 4,


        7, 3, 2,
        2, 6, 7,


        0, 1, 4,
        1, 5, 4
};

const GLfloat Primitives::PLANE_VERT_DATA[20] = {

        -1, 0, -1, 0, 0,
        +1, 0, -1, 1, 0,
        -1, 0, +1, 0, 1,
        +1, 0, +1, 1, 1
};

const GLushort Primitives::PLANE_ELEMENT_DATA[6] = {
        0, 1, 2,
        3, 1, 2
};