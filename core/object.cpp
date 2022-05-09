//
// Created by nicol on 09/05/2022.
//

#include "object.h"

std::string &Object::name() {
    return _name;
}

const std::string &Object::name() const {
    return _name;
}

void Object::Destroy(Object object) {
    object._toDestroy = true;
}
