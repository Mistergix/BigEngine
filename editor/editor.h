//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_EDITOR_H
#define BIG_ENGINE_EDITOR_H

#include "../utils/json_reader.h"
#include <unordered_map>

class Editor {
public:

    [[nodiscard]] static json GetPrefabJson(const std::string &basicString);

    static void Init();

private:
    static std::unordered_map<std::string, std::string> _files;
};


#endif //BIG_ENGINE_EDITOR_H
