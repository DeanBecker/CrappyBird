//
//  Shader.hpp
//  CrappyBird
//
//  Created by Dean Becker on 14/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <string>

#include "gl_headers.h"

#include <unordered_map>

#include "Vector3f.hpp"
#include "Matrix4f.hpp"



class Shader
{
public:
    int programId;

    // Static Shader Instances
    static Shader* BG_Shader;
    static Shader* Bird_Shader;

    Shader(std::string vert, std::string frag);

    static void LoadAll();

    int getAttrib(std::string name);
    int getUniform(std::string name);
    void setUniform1i(std::string name, int value);
    void setUniform1f(std::string name, float value);
    void setUniform2f(std::string name, float x, float y);
    void setUniform3f(std::string name, float x, float y, float z);
    void setUniform3f(std::string name, Vector3f* vec);
    void setUniformMat4f(std::string name, Matrix4f* mat);

    void enable();
    void disable();

    ~Shader();

private:
    std::unordered_map<std::string, GLuint> attribCache;
    std::unordered_map<std::string, GLint> uniformCache;
    bool enabled;
};

#endif /* Shader_hpp */
