//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_PROJECT_SETTINGS_H
#define BIG_ENGINE_PROJECT_SETTINGS_H


#include <string>

class ProjectSettings {
public:
    static std::string GetAssetsPath();
    static int TargetFramerate();
};


#endif //BIG_ENGINE_PROJECT_SETTINGS_H
