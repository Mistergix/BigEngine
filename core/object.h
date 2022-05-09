//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_OBJECT_H
#define BIG_ENGINE_OBJECT_H

#include <string>
#include <vector>

class Object {
public:
    std::string& name();
    [[nodiscard]] const std::string& name() const;
    static void Destroy(Object object);
private:
    std::string _name;
    bool _toDestroy;
};


#endif //BIG_ENGINE_OBJECT_H
