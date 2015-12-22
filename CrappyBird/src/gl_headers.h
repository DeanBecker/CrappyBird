//
//  gl_headers.h
//  CrappyBird
//
//  Created by Dean Becker on 15/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#ifndef gl_headers_h
#define gl_headers_h


#ifdef _WIN32
#include <glew.h>
#endif

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

/// Graphics Structs
struct TextureData_def;
typedef struct TextureData_def
{
	int width, height, imageSize;
	GLuint Id;
} TextureData;
///

#endif /* gl_headers_h */
