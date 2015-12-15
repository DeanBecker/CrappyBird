//
//  Shader.cpp
//  CrappyBird
//
//  Created by Dean Becker on 14/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "Shader.hpp"

extern "C" {
    #include "ShaderUtils.h"
}

std::unordered_map<std::string, GLint> uniformCache;
bool enabled;

Shader* Shader::BG_Shader;

Shader::Shader(std::string vert, std::string frag)
{
	programId = compileProgram(vert.c_str(), frag.c_str());
}

void Shader::LoadAll()
{
    BG_Shader = new Shader("shaders/bg.vert", "shaders/bg.frag");
}

int Shader::getUniform(std::string name)
{
    std::unordered_map<std::string, GLint>::const_iterator lookup = uniformCache.find(name.c_str());

    if (lookup != uniformCache.end()) {
        // Cached value
        return lookup->second;
    }

    GLint uniformLocation = glGetUniformLocation(programId, name.c_str());
    uniformCache.insert( { name, uniformLocation} );

    return uniformLocation;
}

void Shader::setUniform1i(std::string name, int value)
{
    glUniform1i(getUniform(name), value);
}

void Shader::setUniform1f(std::string name, float value)
{
    glUniform1f(getUniform(name), value);
}

void Shader::setUniform2f(std::string name, float x, float y)
{
    glUniform2f(getUniform(name), x, y);
}

void Shader::setUniform3f(std::string name, float x, float y, float z)
{
    glUniform3f(getUniform(name), x, y, z);
}

void Shader::setUniform3f(std::string name, Vector3f vec)
{
	setUniform3f(name, vec.x, vec.y, vec.z);
}

void Shader::setUniformMat4f(std::string name, Matrix4f mat)
{
    glUniformMatrix4fv(getUniform(name), sizeof(float) * 16, GL_FALSE, (const GLfloat *)mat.toBuffer());
}

void Shader::enable()
{
    glUseProgram(programId);
    enabled = true;
}

void Shader::disable()
{
    glUseProgram(0);
    enabled = false;
}

Shader::~Shader()
{
    glDeleteProgram(programId);
}