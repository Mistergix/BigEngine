//
// Created by nicol on 09/05/2022.
//

#include <iostream>
#include "editor.h"
#include "assets_importer.h"

std::unordered_map<std::string, std::string> Editor::_files;


void Editor::Init() {
    _files = AssetsImporter::ImportMetaFiles();
}

json Editor::GetPrefabJson(const std::string &guid) {
    auto path = _files.at(guid);
    std::cout << "Reading prefab " << path << std::endl;
    auto j = JsonReader::GetJsonFile(path);
    std::cout << "Prefab name " << j.at("name") << std::endl;
    return j;
}
