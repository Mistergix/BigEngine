//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_OBJECT_H
#define BIG_ENGINE_OBJECT_H

#include <string>
#include <vector>
#include "../utils/json.hpp"

class Object {
public:
    std::string& name();
    [[nodiscard]] const std::string& name() const;
    virtual void Deserialize(nlohmann::basic_json<> json);
private:
    std::string _name;
    std::string _fileId;
};


#endif //BIG_ENGINE_OBJECT_H
