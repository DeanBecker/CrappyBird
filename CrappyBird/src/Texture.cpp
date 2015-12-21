//
//  Texture.cpp
//  CrappyBird
//
//  Created by Dean Becker on 20/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.

#include "Texture.hpp"

extern "C" {
	#include "TextureUtils.h"
}

static int activeTextures = 0;

static GLenum TextureFormatForBitmapFormat(Bitmap::Format format)
{
	switch (format) {
	case Bitmap::Format_Grayscale: return GL_LUMINANCE;
	case Bitmap::Format_GrayscaleAlpha: return GL_LUMINANCE_ALPHA;
	case Bitmap::Format_RGB: return GL_RGB;
	case Bitmap::Format_RGBA: return GL_RGBA;
	default: throw std::runtime_error("Unrecognised Bitmap::Format");
	}
}

Texture::Texture(std::string filePath)
{
	//textureId = getTextureData(filePath.c_str());
	Bitmap bmp = Bitmap::bitmapFromFile(filePath);
	bmp.flipVertically();
	//GLuint textureId;
	//glGenTextures(1, &textureId);
	//glBindTexture(GL_TEXTURE_2D, textureId);

	//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	//glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,
		0,
		TextureFormatForBitmapFormat(bmp.format()),
		(GLsizei)bmp.width(),
		(GLsizei)bmp.height(),
		0,
		TextureFormatForBitmapFormat(bmp.format()),
		GL_UNSIGNED_BYTE,
		bmp.pixelBuffer());
	glBindTexture(GL_TEXTURE_2D, 0);

	ActiveTexture = activeTextures++;
}

Texture::~Texture()
{
}

void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0 + ActiveTexture);
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}