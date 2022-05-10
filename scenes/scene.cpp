//
// Created by nicol on 09/05/2022.
//

#include "scene.h"
#include "../utils/json_reader.h"
#include "../utils/prefab_utils.h"

#include <utility>

Scene::Scene(std::string path) {
    _path = std::move(path);
    auto j = JsonReader::GetJsonFile(_path);
    _name = j.at("name");

    auto jPrefabs = j.at("prefabs");
    for (int i = 0; i < jPrefabs.size(); ++i) {
        auto jPrefab = jPrefabs.at(i);
        auto instantiatedPrefab = PrefabUtils::InstantiatePrefab(jPrefab.at("source").at("guid"));
    }
}

std::string &Scene::name() {
    return _name;
}

const std::string &Scene::name() const {
    return _name;
}
