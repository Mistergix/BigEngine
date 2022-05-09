//
// Created by nicol on 09/05/2022.
//

#include "editor.h"
#include "assets_importer.h"


Editor::Editor() {
   _files = AssetsImporter::ImportMetaFiles();
}
