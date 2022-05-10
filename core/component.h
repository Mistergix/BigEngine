//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_COMPONENT_H
#define BIG_ENGINE_COMPONENT_H

#include <map>
#include "object.h"
#include "game_object.h"

#define REGISTER_DECLARATION_TYPE(NAME) \
    static DerivedRegister<NAME> reg

#define REGISTER_DEFINITION_TYPE(NAME) \
    DerivedRegister<NAME> NAME::reg(#NAME)

class Component;

template<typename T> Component * createT() { return new T; }

struct ComponentFactory {
    typedef std::map<std::string, Component*(*)()> map_type;
    static Component* CreateInstance(std::string const& s){
        auto it = GetMap()->find(s);
        if(it == GetMap()->end()){return nullptr;}
        return it->second();
    }

protected:
    static map_type * GetMap(){
        if (!map){map = new map_type ;}
        return map;
    }

private:
    static map_type * map;
};

template<typename T>
struct DerivedRegister : ComponentFactory {
    explicit DerivedRegister(std::string const& s){
        GetMap()->insert(std::make_pair(s, &createT<T>));
    }
};

class Component : public Object{
public:
    virtual void OnCreate();
    virtual void OnUpdate(float deltaTime);
    virtual void OnPhysicsUpdate(float physicsDeltaTime);
    virtual void OnRelease();
};


#endif //BIG_ENGINE_COMPONENT_H
