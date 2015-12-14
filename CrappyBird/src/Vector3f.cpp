//
//  Vector3f.cpp
//  CrappyBird
//
//  Created by Dean Becker on 14/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#include "Vector3f.hpp"

Vector3f::Vector3f()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
}

Vector3f::Vector3f(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3f::dot(Vector3f *otherVec)
{
    return (this->x * otherVec->x + this->y * otherVec->y + this->z * otherVec->z);
}