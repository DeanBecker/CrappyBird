//
//  VertexArray.cpp
//  CrappyBird
//
//  Created by Dean Becker on 15/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "VertexArray.hpp"

VertexArray::VertexArray(size_t _count)
{
	count = _count;
	glGenVertexArrays(1, &vao);
}

VertexArray::VertexArray(std::vector<float> vertices,
						 std::vector<unsigned int> indices,
						 std::vector<float> textureCoords,
						 Shader* shader)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Vertex Buffer
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	GLuint posAttrib = shader->getAttrib("pos");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	// UV Buffer
	glGenBuffers(1, &tbo);
	glBindBuffer(GL_ARRAY_BUFFER, tbo);
	glBufferData(GL_ARRAY_BUFFER, textureCoords.size() * sizeof(float), &textureCoords[0], GL_STATIC_DRAW);
	GLuint tcsAttrib = shader->getAttrib("vert_tc");
	glEnableVertexAttribArray(tcsAttrib);
	glVertexAttribPointer(tcsAttrib, 2, GL_FLOAT, false, 0, 0);

	// Vertex Indices
	count = indices.size();
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * count, &indices[0], GL_STATIC_DRAW);

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
		glDrawElements(GL_TRIANGLES, (GLsizei)count, GL_UNSIGNED_INT, (void *)0);
	}
	else {
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}

void VertexArray::render()
{
	bind();
	draw();
}