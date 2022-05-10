#include <iostream>
#include "core/object.h"
#include "editor/editor.h"
#include "core/game.h"

#include "Glew/glew.h"
#include "Glfw/glfw3.h"


void ErrorCallback(int error, const char* desc){
    std::cerr << "Error" << desc << std::endl;
}

int main() {
    // TODO main loop
    // TODO destructors
    // TODO transforms children ?
    // TODO gérer les id dans les fichiers

    Editor::Init();
    Game game;

    game.Run();

    if(!glfwInit()){
        std::cerr << "gltf init fail" << std::endl;
        return -1;
    }

    glfwSetErrorCallback(ErrorCallback);
    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWwindow* p_window = glfwCreateWindow(1280, 720, "test", nullptr, nullptr);

    glfwMakeContextCurrent(p_window);

    glfwSwapInterval(1);
    glEnable(GL_CULL_FACE);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        glfwTerminate();
        std::cerr << "Glew init Fail" << std::endl;
        return  -1;
    }

    while (!glfwWindowShouldClose(p_window) && glfwGetKey(p_window, GLFW_KEY_ESCAPE) != GLFW_PRESS){

        glfwSwapBuffers(p_window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

