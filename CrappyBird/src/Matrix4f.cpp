//
//  Matrix4f.cpp
//  CrappyBird
//
//  Created by Dean Becker on 14/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "Matrix4f.hpp"

#define PI 3.14159265

const int SIZE = 4 * 4;

Matrix4f* Matrix4f::identity()
{
    Matrix4f* identityMatrix = new Matrix4f();

    for (int i = 0; i < SIZE; i++) {
        if (i % 5 == 0) {
            identityMatrix->data[i] = 1.0f;
        } else {
            identityMatrix->data[i] = 0.0f;
        }
    }

    return identityMatrix;
}

Matrix4f* Matrix4f::orthographic(float left, float right, float top, float bottom, float zNear, float zFar)
{
    /* COLUMN MAJOR
     * 0, 4, 8, 12
     * 1, 5, 9, 13
     * 2, 6, 10, 14
     * 3, 7, 11, 15
     */

    Matrix4f* orthographicMatrix = identity();

    orthographicMatrix->data[0 + 0 * 4] = 2.0f / (right - left); //0
    orthographicMatrix->data[1 + 1 * 4] = 2.0f / (top - bottom); //5
    orthographicMatrix->data[2 + 2 * 4] = 2.0f / (zNear - zFar); //10

    orthographicMatrix->data[0 + 3 * 4] = (left + right) / (left - right); //12
    orthographicMatrix->data[1 + 3 * 4] = (bottom + top) / (bottom - top); //13
    orthographicMatrix->data[2 + 3 * 4] = (zFar + zNear) / (zFar - zNear); //14

    return orthographicMatrix;
}

Matrix4f* Matrix4f::translate(Vector3f* vec)
{
    Matrix4f* result = identity();

    result->data[0 + 3 * 4] = vec->x; //12
    result->data[1 + 3 * 4] = vec->y; //13
    result->data[2 + 3 * 4] = vec->z; //14

    return result;
}

Matrix4f* Matrix4f::rotate(float angle)
{
    Matrix4f* result = identity();
    float r = angle * PI / 180.0f;
    float cosA = (float)cos(r);
    float sinA = (float)sin(r);

    result->data[0 + 0 * 4] = cosA;
    result->data[1 + 0 * 4] = sinA;
    result->data[0 + 1 * 4] = -sinA;
    result->data[1 + 1 * 4] = cosA;



    return result;
}

Matrix4f* Matrix4f::multiply(Matrix4f *otherMat)
{
    Matrix4f* result = new Matrix4f();

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            float sum = 0.0f;
            for (int e = 0; e < 4; e++) {
                sum += this->data[x + e * 4] * otherMat->data[e + y * 4];
            }
            result->data[x + y * 4] = sum;
        }
    }

    return result;
}

const GLfloat* Matrix4f::toBuffer()
{
    return (const GLfloat *)data;
}