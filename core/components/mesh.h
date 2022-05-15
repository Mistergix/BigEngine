//
// Created by pouyoupy on 10/05/2022.
//

#ifndef BIG_ENGINE_MESH_H
#define BIG_ENGINE_MESH_H

#include "../component.h"
#include <Glew/glew.h>

class Mesh : public Component {
public:
    virtual void Deserialize(nlohmann::basic_json<> json) override;

    GLuint vao;
    GLuint vbo;

    GLfloat *verticies;
    GLushort *indicies;

    int vertSize; //Size in bytes
    int elementSize; //Size in bytes

    int ID; //So that they can be identified;
    int numberOfIndices; //Length of elements array
    int numVerticies; //Length of vertex array

    Mesh();
    Mesh(int nv, GLfloat* v, int ni, GLushort* i);

    void Init(GLfloat* vertices, unsigned int numberOfVertices, GLushort * indices, unsigned int numberOfIndices);

    void draw();

private:
    REGISTER_DECLARATION_TYPE(Mesh)

};


#endif //BIG_ENGINE_MESH_H
