//
//  Shader.cpp
//  CrappyBird
//
//  Created by Dean Becker on 14/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "Shader.hpp"

std::unordered_map<std::string, GLint> uniformCache;

void Shader::LoadAll()
{
    // When we've got something to actually load....
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

}

void Shader::setUniformMat4f(std::string name, Matrix4f mat)
{
    
}