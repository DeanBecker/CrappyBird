//
//  Pipe.hpp
//  CrappyBird
//
//  Created by Dean Becker on 03/01/2016.
//  Copyright © 2016 Dean Becker. All rights reserved.
//

#ifndef Pipe_hpp
#define Pipe_hpp

#include <vector>

#include "IRenderable.hpp"

#include "VertexArray.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Matrix4f.hpp"

class Pipe : public IRenderable
{
public:
	Pipe();
	~Pipe();

	void update();
	void render();

private:
	bool inverted;
	VertexArray* model;
	Texture* texture;
	Shader* pipeShader;
};

#endif /* Pipe_hpp */