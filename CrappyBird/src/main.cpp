////
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

void update()
{

}

void render()
{

}


void init()
{
    if (!glfwInit()) {
        std::cout << "GLFW could not initialise!";
        return;
    }

    glfwSetErrorCallback(error_callback);

    window = glfwCreateWindow(width, height, "Crappy Bird", NULL, NULL);

    if (!window) {
        glfwTerminate();
        std::cout << "GLFW could not create a window!";
        return;
    }

    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    glfwShowWindow(window);
}

void run()
{
    init();

    while (running) {
        if (glfwWindowShouldClose(window)) {
            running = false;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
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