//
// Created by pouyoupy on 10/05/2022.
//

#ifndef BIG_ENGINE_RENDERER_H
#define BIG_ENGINE_RENDERER_H

#include "../component.h"
#include <Glew/glew.h>
#include <Glm\glm.hpp>

class Renderer : public Component {



public:

    virtual void Deserialize(nlohmann::basic_json<> json) override;

    Renderer();

    glm::vec3 colour;

    Renderer(glm::vec3 colour);
    void draw();

private:
    REGISTER_DECLARATION_TYPE(Renderer)
};


#endif //BIG_ENGINE_RENDERER_H
