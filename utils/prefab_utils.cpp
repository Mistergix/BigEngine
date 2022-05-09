//
// Created by nicol on 09/05/2022.
//

#include <iostream>
#include "prefab_utils.h"
#include "../editor/editor.h"

GameObject PrefabUtils::InstantiatePrefab(const std::string& guid) {
    auto jPrefab =  Editor::GetPrefabJson(guid);
    std::cout << "TODO populate prefab with data then modifications" << std::endl;
    return GameObject();
}
