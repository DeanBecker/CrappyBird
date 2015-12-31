//
//  Bird.cpp
//  CrappyBird
//
//  Created by Dean Becker on 24/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "Bird.hpp"

Bird::Bird()
{
    ///Bird
    std::vector<float> vertices =
    {
        -2.0f, -2.0f * 9.0f / 16.0f, 0.1f,
        -2.0f, 2.0f * 9.0f / 16.0f, 0.1f,
        2.0f, 2.0f * 9.0f / 16.0f, 0.1f,
        2.0f, -2.0f * 9.0f / 16.0f, 0.1f
    };

    std::vector<unsigned int> indices =
    {
        0, 1, 2,
        2, 3, 0
    };
    ///

    std::vector<float> texCoords =
    {
        0, 1,
        0, 0,
        1, 0,
        1, 1
    };

    birdShader = Shader::Bird_Shader;
    model = new VertexArray(vertices, indices, texCoords, birdShader);
    tex = new Texture("res/bird.png", FILE_TYPE::PNG);
}

Bird::~Bird()
{
    if (tex) delete tex;
    if (model) delete model;
}

void Bird::update()
{

}

void Bird::render()
{
    birdShader->enable();
    if (tex)
    {
        tex->bind();
    }

    Matrix4f* translateMat = Matrix4f::identity();
    birdShader->setUniformMat4f("vw_mat", translateMat);
    model->render();

    birdShader->disable();
    if (tex) tex->unbind();
}

void Bird::draw()
{

}

void Bird::enable()
{

}

void Bird::disable()
{
    
}