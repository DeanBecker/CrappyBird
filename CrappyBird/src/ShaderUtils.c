//
//  ShaderUtils.c
//  CrappyBird
//
//  Created by Dean Becker on 15/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "ShaderUtils.h"


char* getFileContents(const char * fileName)
{
#ifdef _WIN32
#ifdef _DEBUG
#include <stdio.h>  /* defines FILENAME_MAX */
#include <direct.h>
#define GetCurrentDir _getcwd
	char cCurrentPath[FILENAME_MAX];
	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return errno;
	}
	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
	printf("The current working directory is %s\n", cCurrentPath);
#endif //_DEBUG
#endif //_WIN32

    char* contents;
    long inputSize;
    FILE* f = fopen(fileName, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        inputSize = ftell(f);
        rewind(f);

        contents = (char *)malloc(inputSize+1 * sizeof(char));
        fread(contents, sizeof(char), inputSize, f);
        fclose(f);

        contents[inputSize] = '\0';
    }

    return contents;
}

void logGLSLCompilationError(GLint shaderId)
{
    GLint errorLen = 0;
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &errorLen);
    char **errorBuffer = malloc(errorLen * sizeof(char));
    glGetShaderInfoLog(shaderId, errorLen, &errorLen, errorBuffer);

    printf("%s", errorBuffer);

	free(errorBuffer);
}

int compileProgram(const char * vertexFile, const char * fragmentFile)
{
    const GLchar* vertexShader = getFileContents(vertexFile);
    const GLchar* fragmentShader = getFileContents(fragmentFile);

    int program = glCreateProgram();
    int vertId = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertId, 1, &vertexShader, NULL);
    glCompileShader(vertId);
    GLint isCompiled = 0;
    glGetShaderiv(vertId, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        printf("Failed to compile vertex shader: \n");
        logGLSLCompilationError(vertId);
    }

    int fragId = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragId, 1, &fragmentShader, NULL);
    glCompileShader(fragId);
    glGetShaderiv(fragId, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        printf("Failed to compile fragment shader: \n");
        logGLSLCompilationError(fragId);
    }

    glAttachShader(program, vertId);
    glAttachShader(program, fragId);
    glLinkProgram(program);

    //throw exception if linking failed
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        printf("Program linking failure: ");

        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
        char **strInfoLog = malloc((infoLogLength + 1) * sizeof(char));
        glGetProgramInfoLog(program, infoLogLength, &infoLogLength, strInfoLog);
        printf("%s", strInfoLog);

		free(strInfoLog);
        glDeleteProgram(program);
    }


    glValidateProgram(program);


    glDeleteShader(vertId);
    glDeleteShader(fragId);
    free(vertexShader);
    free(fragmentShader);

    return program;
}

