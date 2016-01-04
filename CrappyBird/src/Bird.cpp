//
//  Bird.cpp
//  CrappyBird
//
//  Created by Dean Becker on 24/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "Bird.hpp"

#include "Input.hpp"

#define BIRD_SIZE 0.5
#define FALL_ACCEL 0.005

Bird::Bird()
{
    ///Bird
    std::vector<float> vertices =
    {
        -BIRD_SIZE, -BIRD_SIZE * 9.0f / 16.0f, 0.2f,
        -BIRD_SIZE, BIRD_SIZE * 9.0f / 16.0f, 0.2f,
		BIRD_SIZE, BIRD_SIZE * 9.0f / 16.0f, 0.2f,
		BIRD_SIZE, -BIRD_SIZE * 9.0f / 16.0f, 0.2f
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

	/// Graphics
    birdShader = Shader::Bird_Shader;
    model = new VertexArray(vertices, indices, texCoords, birdShader);
    tex = new Texture("res/bird.png", FILE_TYPE::PNG);
	///

	position = new Vector3f();
}

Bird::~Bird()
{
    if (tex) delete tex;
    if (model) delete model;
	if (position) delete position;
}

void Bird::update()
{
	position->y -= pos_delta;
	if (isKeyDown(GLFW_KEY_SPACE) == true)
	{
		pos_delta = 0.15f;
	}
	else {
		pos_delta -= FALL_ACCEL;
	}

	rotation = -pos_delta * 90.0f;
}

void Bird::render()
{
    birdShader->enable();
    if (tex)
    {
        tex->bind();
    }

	Matrix4f* translateMat = Matrix4f::identity()->translate(position)->multiply(Matrix4f::rotate(rotation));
    birdShader->setUniformMat4f("vw_mat", translateMat);
    model->render();
    if (translateMat) delete translateMat;

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