//
//  Texture.cpp
//  CrappyBird
//
//  Created by Dean Becker on 20/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.

#include "Texture.hpp"

Texture::Texture(std::string filePath)
{
	textureId = loadTexture(filePath);
}

Texture::~Texture()
{
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

int Texture::loadTexture(std::string filePath)
{
	GLuint tex;
	glGenTextures(1, &tex);


	return tex;
}

