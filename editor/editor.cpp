//
// Created by nicol on 09/05/2022.
//

#include "editor.h"
#include "../core/config/project_settings.h"

#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;




Editor::Editor() {
    auto assetPath = ProjectSettings::GetAssetsPath();

}
