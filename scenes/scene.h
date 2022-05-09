//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_SCENE_H
#define BIG_ENGINE_SCENE_H


#include <string>
#include "../core/game_object.h"

class Scene {
public:
    explicit Scene(std::string path);
    std::string& name();
    [[nodiscard]] const std::string& name() const;
private:
    std::string _path;
    std::string _name;
    std::vector<GameObject*> _objects;
};


#endif //BIG_ENGINE_SCENE_H
