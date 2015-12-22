//
//  Texture.hpp
//  CrappyBird
//
//  Created by Dean Becker on 20/12/2015.
//  Copyright � 2015 Dean Becker. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <string>

#include "gl_headers.h"
#include "Bitmap.hpp"

class Texture 
{
public:
	Texture(std::string filePath);
	~Texture();

	void bind();
	void unbind();

private:
	GLuint textureId;
	GLint ActiveTexture;
};

#endif /* Texture_hpp */