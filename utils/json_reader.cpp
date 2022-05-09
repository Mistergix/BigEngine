//
// Created by nicol on 09/05/2022.
//

#include "json_reader.h"

json JsonReader::GetJsonFile(const std::string &filepath) {
    std::ifstream stream(filepath);
    json j = json::parse(stream);
    return j;
}
