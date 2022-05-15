//
// Created by pouyoupy on 10/05/2022.
//

#include "mesh.h"
#include "../Math/primitives.h"

REGISTER_DEFINITION_TYPE(Mesh)

void Mesh::Deserialize(nlohmann::basic_json<> json) {
    Component::Deserialize(json);
    Init(const_cast<GLfloat *>(primitives.CUBE_VERT_DATA), 36, const_cast<GLushort *>(primitives.CUBE_ELEMENT_DATA), 24);
}

Mesh::Mesh() {
    vertSize = 0;
    elementSize = 0;
    vao = 0;
    vbo = 0;
}

void Mesh::Init(GLfloat* vertices, unsigned int numberOfVertices, GLushort * indices, unsigned int numberOfIndices)
{
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numberOfIndices * sizeof(indices[0]), indices, GL_STATIC_DRAW);

    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, numberOfVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0])*8, 0);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(3 * sizeof(vertices[0])));

    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(5 * sizeof(vertices[0])));

    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void Mesh::draw(){
    glBindVertexArray(vao);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);

    glDrawElements(GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}


