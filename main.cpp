#include "core/object.h"
#include "editor/editor.h"
#include "core/game.h"


int main() {
    // TODO main loop
    // TODO destructors
    // TODO transforms children ?
    // TODO gérer les id dans les fichiers

    Editor::Init();
    Game game;

    game.Run();
    return 0;
}

