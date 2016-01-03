//
//  Pipe.cpp
//  CrappyBird
//
//  Created by Dean Becker on 03/01/2016.
//  Copyright © 2016 Dean Becker. All rights reserved.
//

#include "Pipe.hpp"

#define PIPE_HEIGHT 3.0f
#define PIPE_WIDTH 0.5f

Pipe::Pipe()
{
	std::vector<float> vertices = 
	{
		-PIPE_HEIGHT, -PIPE_HEIGHT * 9.0f / 16.0f, 0.1f,
		-PIPE_HEIGHT, PIPE_HEIGHT * 9.0f / 16.0f, 0.1f,
		PIPE_HEIGHT, PIPE_HEIGHT * 9.0f / 16.0f, 0.1f,
		PIPE_HEIGHT, -PIPE_HEIGHT * 9.0f / 16.0f, 0.1f
	};
	std::vector<unsigned int> indices = 
	{
		0, 1, 2,
		2, 3, 0
	};
	std::vector<float> texCoords = 
	{
		0, 1,
		0, 0,
		1, 0,
		1, 1
	};
	
	pipeShader = Shader::Pipe_Shader;
	model = new VertexArray(vertices, indices, texCoords, pipeShader);
	texture = new Texture("res/tube.png", FILE_TYPE::PNG);
}

Pipe::~Pipe()
{
	if (model) delete model;
	if (texture) delete texture;
}

void Pipe::update()
{
}

void Pipe::render()
{
	pipeShader->enable();
	if (texture)
	{
		texture->bind();
	}

	Matrix4f* translateMat = Matrix4f::identity();
	pipeShader->setUniformMat4f("vw_mat", translateMat);
	model->render();
	if (translateMat) delete translateMat;

	model->unbind();
	if (texture)
	{
		texture->unbind();
	}
	pipeShader->disable();
}
