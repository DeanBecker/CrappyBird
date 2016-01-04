//
//  Pipe.cpp
//  CrappyBird
//
//  Created by Dean Becker on 03/01/2016.
//  Copyright � 2016 Dean Becker. All rights reserved.
//

#include "Pipe.hpp"

#define PIPE_HEIGHT 3.0f
#define PIPE_WIDTH 0.5f

Pipe::Pipe(float _xOffset)
{
	xOffset = _xOffset;
	xScroll = -0.04f;

	std::vector<float> vertices = 
	{
		-PIPE_WIDTH, -PIPE_HEIGHT * 9.0f / 16.0f, 0.1f,
		-PIPE_WIDTH, PIPE_HEIGHT * 9.0f / 16.0f, 0.1f,
		PIPE_WIDTH, PIPE_HEIGHT * 9.0f / 16.0f, 0.1f,
		PIPE_WIDTH, -PIPE_HEIGHT * 9.0f / 16.0f, 0.1f
	};
	std::vector<unsigned int> indices = 
	{
		0, 1, 2,
		2, 3, 0
	};
	std::vector<float> texCoords = 
	{
		0, 0,
		0, 1,
		1, 1,
		1, 0
	};
	
	pipeShader = Shader::Pipe_Shader;
	model = new VertexArray(vertices, indices, texCoords, pipeShader);
	texture = new Texture("res/tube.png", FILE_TYPE::PNG);

	Vector3f* adjustVec = new Vector3f(8.0f, 4.0f, 0.0f);
	Matrix4f* adjustMat = Matrix4f::translate(adjustVec);
	transformMat = transformMat->multiply(adjustMat);

	delete adjustMat;
	delete adjustVec;
}

Pipe::~Pipe()
{
	delete model;
	delete texture;
    delete transformMat;
}

void Pipe::update()
{
	Vector3f* scrollVec = new Vector3f(xScroll, 0.0f, 0.0f);
	Matrix4f* translateMat = Matrix4f::translate(scrollVec);
	modelMat = modelMat->multiply(translateMat);
	delete translateMat;
}

void Pipe::render()
{
	pipeShader->enable();
	if (texture)
	{
		texture->bind();
	}

	pipeShader->setUniformMat4f("mo_mat", modelMat);
	pipeShader->setUniformMat4f("vw_mat", transformMat);
    pipeShader->setUniform1i("inverted", inverted);
	model->render();

	model->unbind();
	if (texture)
	{
		texture->unbind();
	}
	pipeShader->disable();
}
