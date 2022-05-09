//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_PREFAB_UTILS_H
#define BIG_ENGINE_PREFAB_UTILS_H


#include <string>
#include "../core/game_object.h"

class PrefabUtils {
public:
    static GameObject InstantiatePrefab(const std::string& path);
};


#endif //BIG_ENGINE_PREFAB_UTILS_H
