//
//  Bird.hpp
//  CrappyBird
//
//  Created by Dean Becker on 24/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include <vector>

#include "Shader.hpp"
#include "VertexArray.hpp"
#include "Texture.hpp"

class Bird
{
public:
    Bird();
    ~Bird();

    void update();
    void render();
    void draw();
    void enable();
    void disable();

    int width, height;

private:
    VertexArray* model;
    Texture* tex;
    Shader* birdShader;
};

#endif /* Bird_hpp */
