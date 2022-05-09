//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_COMPONENT_H
#define BIG_ENGINE_COMPONENT_H


#include "object.h"

class Component : public Object{
public:
    virtual void Process();
};


#endif //BIG_ENGINE_COMPONENT_H
