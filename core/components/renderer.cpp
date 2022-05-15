//
// Created by pouyoupy on 10/05/2022.
//

#include "renderer.h"
#include "../game_object.h"
#include "mesh.h"

REGISTER_DEFINITION_TYPE(Renderer)

void Renderer::Deserialize(nlohmann::basic_json<> json) {
    Component::Deserialize(json);
    colour = glm::vec3(1, 0, 0.5f);
}

Renderer::Renderer(glm::vec3 colour){
    this->colour = colour;
}

void Renderer::draw(){
    gameObject()->GetComponent<Mesh>()->draw();

}

Renderer::Renderer() {

}
