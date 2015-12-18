//
//  Level.hpp
//  CrappyBird
//
//  Created by Dean Becker on 16/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp

#include <stdio.h>
#include <vector>

#include "Shader.hpp"
#include "VertexArray.hpp"

class Level
{
public:
    Level();
    ~Level();

    void update();
    void render();

    float rot;
};

#endif /* Level_hpp */
