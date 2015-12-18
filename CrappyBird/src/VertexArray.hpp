//
//  VertexArray.hpp
//  CrappyBird
//
//  Created by Dean Becker on 15/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include <stdio.h>
#include <vector>

#include "gl_headers.h"
#include "Shader.hpp"

class VertexArray
{
public:
    VertexArray(size_t _count);
    VertexArray(std::vector<float> vertices,
                std::vector<unsigned int> indices,
                std::vector<float> textureCoords,
                Shader* shader);

    void bind();
    void unbind();
    void draw();
    void render();

private:
    GLuint vao, vbo, ibo, tbo;
    size_t count;
};

#endif /* VertexArray_hpp */
