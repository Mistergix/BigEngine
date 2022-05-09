//
// Created by nicol on 09/05/2022.
//

#include "assets_importer.h"
#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
#include <regex>
#include "../utils/json_reader.h"

std::unordered_map<std::string, std::string> AssetsImporter::ImportMetaFiles() {
    std::cout << "Importing Meta Files" << std::endl;
    auto assetPath = ProjectSettings::GetAssetsPath();
    std::unordered_map<std::string , std::string > files;
    std::string ext = ".meta";
    for(auto &p : fs::recursive_directory_iterator(assetPath)){
        if(p.path().extension() == ext){
            std::string string = p.path().string();
            auto j = JsonReader::GetJsonFile(string);
            auto gui = j.at("guid");
            string = std::regex_replace(string, std::regex(".meta"), "");
            std::cout <<  gui << " : " << string << '\n';
            files.insert(std::make_pair(gui, string));
        }
    }
    std::cout << "END Importing Meta Files" << std::endl << std::endl;
    return files;
}
