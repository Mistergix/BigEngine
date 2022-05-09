//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_ASSETS_IMPORTER_H
#define BIG_ENGINE_ASSETS_IMPORTER_H

#include "../core/config/project_settings.h"
#include <unordered_map>

class AssetsImporter {

public:
    static std::unordered_map<std::string, std::string> ImportMetaFiles();
};


#endif //BIG_ENGINE_ASSETS_IMPORTER_H
