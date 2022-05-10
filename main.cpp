#include <iostream>
#include "core/game_time.h"
#include "core/object.h"
#include "core/game_object.h"
#include "core/components/transform.h"
#include "scenes/scene.h"
#include "editor/editor.h"

#include "Glew/glew.h"
#include "Glfw/glfw3.h"


void HandleInput();

void ErrorCallback(int error, const char* desc){
    std::cerr << "Error" << desc << std::endl;
}

int main() {
    Editor::Init();

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



    std::string scenePath = "Assets/Scenes/SceneTest.scene";
    Scene scene(scenePath);
    std::cout << scene.name() << std::endl;

    /*
    Time time;
    auto isRunning = true;
    while(isRunning){
        HandleInput();
        LogicUpdate();
        PhysicsUpdate();
        Render();

        time.UpdateTime();
        if(time.CurrentTime() > 10.0){
            isRunning = false;
        }
    }*/
    return 0;
}

void HandleInput() {
    // Utiliser une lib ?
    // Stocker et dater les inputs
}
