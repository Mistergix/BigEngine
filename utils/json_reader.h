//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_JSON_READER_H
#define BIG_ENGINE_JSON_READER_H
#include "../utils/json.hpp"
#include "fstream"
#include <sstream>

using json = nlohmann::json;

class JsonReader {
public:
    static json GetJsonFile(const std::string& filepath);
};


#endif //BIG_ENGINE_JSON_READER_H
