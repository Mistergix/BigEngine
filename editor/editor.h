//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_EDITOR_H
#define BIG_ENGINE_EDITOR_H


#include <unordered_map>

class Editor {
public:
    Editor();
private:
    std::unordered_map<std::string, std::string> _files;
};


#endif //BIG_ENGINE_EDITOR_H
