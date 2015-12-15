//
//  Matrix4f.hpp
//  CrappyBird
//
//  Created by Dean Becker on 14/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#ifndef Matrix4f_hpp
#define Matrix4f_hpp

#include <stdio.h>
#include <math.h>

#include "Vector3f.hpp"

class Matrix4f
{
public:
    static Matrix4f identity();
    static Matrix4f orthographic(float left,
                                 float right,
                                 float top,
                                 float bottom,
                                 float zNear,
                                 float zFar);
    static Matrix4f translate(Vector3f* vec);
    static Matrix4f rotate(float angle);

    Matrix4f multiply(Matrix4f *otherMat);
    float* toBuffer();

private:
    float data[];
};

#endif /* Matrix4f_hpp */
