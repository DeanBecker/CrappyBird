//
////  main.cpp
////  CrappyBird
////
////  Created by Dean Becker on 14/12/2015.
////  Copyright © 2015 Dean Becker. All rights reserved.
////
//
//#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Input.hpp"

#include <iostream>

static int width = 1280;
static int height = 720;
static float ratio = width / (float)height;

static bool running = false;

static GLFWwindow *window;

static void error_callback(int error, const char* description)
{
    std::cout << description << std::endl;
}

void init()
{
    if (!glfwInit()) {
        std::cout << "GLFW could not initialise!" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwSetErrorCallback(error_callback);

    window = glfwCreateWindow(width, height, "Crappy Bird", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "GLFW could not create a window!" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
}

void update()
{
    glfwPollEvents();
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    glfwSwapBuffers(window);
}

void run()
{
    init();

    double lastTime = glfwGetTime();
    int frames = 0;

    while (running) {
        double now = glfwGetTime();
        frames++;
        if (now - lastTime >= 1.0) {
            printf("%f ms/frame\n", 1000.0/double(frames));
            frames = 0;
            lastTime += 1.0;
        }

        update();
        render();

        int error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cout << error << std::endl;
        }

        if (glfwWindowShouldClose(window)) {
            running = false;
        }
    }
}

void stop()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void start()
{
    running = true;
    run();
    stop();
}

int main(int argc, const char * argv[])
{
    start();

    return 0;
}