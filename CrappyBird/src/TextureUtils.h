//
//  TextureUtils.h
//  CrappyBird
//
//  Created by Dean Becker on 20/12/2015.
//  Copyright � 2015 Dean Becker. All rights reserved.
//

#ifndef TextureUtils_h
#define TextureUtils_h

#include <stdio.h>
#include <stdlib.h>

#include "gl_headers.h"

TextureData getTextureData(const char* filePath, FILE_TYPE type);

#endif /* TextureUtils_h */