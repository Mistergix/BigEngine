//
// Created by nicol on 09/05/2022.
//

#include "scene.h"
#include "../json.hpp"
#include "fstream"
#include <sstream>

using json = nlohmann::json;

#include <utility>
#include <iostream>

Scene::Scene(std::string path) {
    _path = std::move(path);
    std::ifstream stream(_path);
    json j = json::parse(stream);
    _name = j.at("name");
}

std::string &Scene::name() {
    return _name;
}

const std::string &Scene::name() const {
    return _name;
}
