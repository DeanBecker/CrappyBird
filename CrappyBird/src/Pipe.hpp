//
//  Pipe.hpp
//  CrappyBird
//
//  Created by Dean Becker on 03/01/2016.
//  Copyright � 2016 Dean Becker. All rights reserved.
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

    bool inverted = false;
    
private:
	VertexArray* model;
	Texture* texture;
	Shader* pipeShader;
   	Matrix4f* translateMat = Matrix4f::identity();
};

#endif /* Pipe_hpp */