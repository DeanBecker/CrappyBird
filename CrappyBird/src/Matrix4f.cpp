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

float data[SIZE];

Matrix4f Matrix4f::identity()
{
    Matrix4f identityMatrix;

    for (int i = 0; i < SIZE; i++) {
        if (i % 5 == 0) {
            identityMatrix.data[i] = 1.0f;
        } else {
            identityMatrix.data[i] = 0.0f;
        }
    }

    return identityMatrix;
}

Matrix4f Matrix4f::orthographic(float left, float right, float top, float bottom, float zNear, float zFar)
{
    Matrix4f orthographicMatrix;

    orthographicMatrix.data[0 + 0 * 4] = 2.0f / (right - left);
    orthographicMatrix.data[1 + 1 * 4] = 2.0f / (top - bottom);
    orthographicMatrix.data[2 + 2 * 4] = 2.0f / (zNear - zFar);

    orthographicMatrix.data[0 + 3 * 4] = (left + right) / (left - right);
    orthographicMatrix.data[1 + 3 * 4] = (bottom + top) / (bottom - top);
    orthographicMatrix.data[2 + 3 * 4] = (zFar + zNear) / (zFar - zNear);

    return orthographicMatrix;
}

Matrix4f Matrix4f::translate(Vector3f* vec)
{
    Matrix4f result = identity();

    result.data[0 + 3 * 4] = vec->x;
    result.data[1 + 3 * 4] = vec->y;
    result.data[2 + 3 * 4] = vec->z;

    return result;
}

Matrix4f Matrix4f::rotate(float angle)
{
    Matrix4f result = identity();
    float r = angle * PI / 180;
    float cosA = cos(angle);
    float sinA = sin(angle);

    result.data[0 + 0 * 4] = cosA;
    result.data[1 + 0 * 4] = sinA;
    result.data[0 + 1 * 4] = -sinA;
    result.data[1 + 1 * 4] = cosA;



    return result;
}

Matrix4f Matrix4f::multiply(Matrix4f *otherMat)
{
    Matrix4f result;

    // TODO
    
    return result;
}