//
//  Input.cpp
//  CrappyBird
//
//  Created by Dean Becker on 14/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "Input.hpp"

static bool keys[65536];

void key_callback(GLFWwindow* window,
                         int key,
                         int scancode,
                         int action,
                         int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    keys[key] = action != GLFW_RELEASE;
}

bool isKeyDown(int key)
{
    return keys[key];
}