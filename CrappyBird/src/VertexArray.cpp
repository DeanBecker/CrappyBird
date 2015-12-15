//
//  VertexArray.cpp
//  CrappyBird
//
//  Created by Dean Becker on 15/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "VertexArray.hpp"

VertexArray::VertexArray(int _count)
{
    count = _count;
    glGenVertexArrays(1, &vao);
}

VertexArray::VertexArray(std::vector<float> vertices,
                         std::vector<short> indices,
                         std::vector<float> textureCoords)
{
    count = (int)indices.size();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenFramebuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(Shader::VERTEX_ATTRIB, 3, GL_FLOAT, false, 0, 0);
    glEnableVertexAttribArray(Shader::VERTEX_ATTRIB);

    glGenFramebuffers(1, &tbo);
    glBindBuffer(GL_ARRAY_BUFFER, tbo);
    glBufferData(GL_ARRAY_BUFFER, textureCoords.size() * sizeof(float), &textureCoords[0], GL_STATIC_DRAW);
    glVertexAttribPointer(Shader::TCOORD_ATTRIB, 2, GL_FLOAT, false, 0, 0);
    glEnableVertexAttribArray(Shader::TCOORD_ATTRIB);

    glGenFramebuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(short), &indices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void VertexArray::bind()
{
    glBindVertexArray(vao);
    if (ibo > 0) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    }
}

void VertexArray::unbind()
{
    if (ibo > 0) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    glBindVertexArray(0);
}

void VertexArray::draw()
{
    if (ibo > 0) {
        glDrawElements(GL_TRIANGLES, count, GL_SHORT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, count);
    }
}

void VertexArray::render()
{
    bind();
    draw();
}