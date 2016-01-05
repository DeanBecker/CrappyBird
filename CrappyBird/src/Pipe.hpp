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
	Pipe()
		: Pipe(0.0f) {};
	Pipe(float _xOffset);
	~Pipe();

	void init();
	void update();
	void render();

    bool inverted = false;
    
protected:
	static VertexArray* model;
	static Texture* texture;
	static Shader* pipeShader;

private:
   	Matrix4f* transformMat = Matrix4f::identity();
	Matrix4f* mlMatrix = Matrix4f::identity();

	float xOffset = 0.0f;
	float xScroll = 0.0f;
};

#endif /* Pipe_hpp */