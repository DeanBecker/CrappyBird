//
//  Level.cpp
//  CrappyBird
//
//  Created by Dean Becker on 16/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "Level.hpp"

VertexArray* background;
Matrix4f* translateMat = Matrix4f::identity();
Texture* tex;

void Level::update()
{

}

void Level::render()
{
	if (tex)
	{
		tex->bind();
		Shader::BG_Shader->setUniform1i("tex", 0);
	}
    Shader* bg = Shader::BG_Shader;
    bg->enable();

    translateMat = translateMat->multiply(Matrix4f::rotate(rot));
    bg->setUniformMat4f("vw_mat", translateMat);
    background->render();

	background->unbind();
    bg->disable();
	if (tex) tex->unbind();
}

Level::Level()
{
    /// Debug Triangle
   /* std::vector<float> vertices =
    {
        0.0f, 0.8f, 0.0f,
        -0.8f,-0.8f, 0.0f,
        0.8f,-0.8f, 0.0f,
    };

    std::vector<unsigned int> indices =
    {
        0, 1, 2
    };

    rot = 0.5f;*/
    ///
	
	/// Background Geometry
    std::vector<float> vertices =
    {
        -10.0f, -10.0f * 9.0f / 16.0f, 0.0f,
        -10.0f, 10.0f * 9.0f / 16.0f, 0.0f,
        0.0f, 10.0f * 9.0f / 16.0f, 0.0f,
        0.0f, -10.0f * 9.0f / 16.0f, 0.0f
    };

    std::vector<unsigned int> indices =
    {
        0, 1, 2,
        2, 3, 0
    };
	///

    std::vector<float> tcs =
    {
        0, 1,
        0, 0,
        1, 0,
        1, 1
    };

	tex = new Texture("res/bg.bmp");
    background = new VertexArray(vertices, indices, tcs, Shader::BG_Shader);
}

Level::~Level()
{
	if (tex) delete tex;
    if (background) delete background;
    if (translateMat) delete translateMat;
}