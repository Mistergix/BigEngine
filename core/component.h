//
// Created by nicol on 09/05/2022.
//

#ifndef BIG_ENGINE_COMPONENT_H
#define BIG_ENGINE_COMPONENT_H

#include <map>
#include <iostream>
#include "object.h"

#define REGISTER_DECLARATION_TYPE(NAME) \
static DerivedRegister<NAME> reg;   \
static DerivedComponentTable regTable;

#define REGISTER_DEFINITION_TYPE(NAME) \
DerivedRegister<NAME> NAME::reg(#NAME); \
DerivedComponentTable NAME::regTable(#NAME);

#define FIND_ALL_COMPONENTS(NAME) ComponentTable::FindAllComponents(#NAME)

class Component : public Object{
public:
    virtual void OnCreate();
    virtual void OnUpdate(float deltaTime);
    virtual void OnPhysicsUpdate(float physicsDeltaTime);
    virtual void OnRelease();
};

struct ComponentTable{
    typedef std::map<std::string, std::vector<Component*>*> table_type;

    static void RegisterComponent(Component* component, const std::string& className){
        auto compList = FindAllComponents(className);
        if(!compList){return;}
        compList->push_back(component);
        _componentsList.insert(std::make_pair(component, className));
        std::cout << "Adding new component to table " << className << std::endl;
    }

    static void UnregisterComponent(Component *pComponent){
        auto className = _componentsList.at(pComponent);
        auto compList = FindAllComponents(className);
        if(!compList){return;}
        auto listIt = std::find(compList->begin(), compList->end(), pComponent);
        compList->erase(listIt);
        _componentsList.erase(pComponent);
        std::cout << "Removing component from table of type " << className <<  std::endl;
    }

    static std::vector<Component*>* FindAllComponents(const std::string& className){
        auto it = GetTable()->find(className);
        if(it == GetTable()->end()) {
            std::cout << "Component type not found in table " << className << std::endl;
            return nullptr;
        }
        return it->second;
    }

protected:
    static table_type * GetTable(){
        if (!_table){_table = new table_type ;}
        return _table;
    }
private:
    static table_type * _table;
    static std::map<Component*, std::string> _componentsList;
};

struct DerivedComponentTable : ComponentTable{
    explicit DerivedComponentTable(const std::string& className){
        std::cout << "Register new component type to table " << className << std::endl;
        auto* components = new std::vector<Component*>;
        GetTable()->insert(std::make_pair(className, components));
    }
};

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
        if (!_map){_map = new map_type ;}
        return _map;
    }

private:
    static map_type * _map;
};

template<typename T>
struct DerivedRegister : ComponentFactory {
    explicit DerivedRegister(std::string const& s){
        GetMap()->insert(std::make_pair(s, &createT<T>));
    }
};

#endif //BIG_ENGINE_COMPONENT_H
