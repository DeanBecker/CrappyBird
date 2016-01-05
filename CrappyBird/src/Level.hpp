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
#include "Texture.hpp"
#include "IRenderable.hpp"

#include "Bird.hpp"
#include "Pipe.hpp"

class Level : public IRenderable
{
public:
    Level();
    ~Level();

    void update();
    void render();

    float rot = 0.0f;

private:
    VertexArray* background;
    Matrix4f* translateMat = Matrix4f::identity();
    Texture* tex;

    IRenderable* bird;
    float xScroll = 0.0f;
	std::vector<IRenderable *> pipes;
	int index = 0;
};

#endif /* Level_hpp */
