//
//  Vector3f.hpp
//  CrappyBird
//
//  Created by Dean Becker on 14/12/2015.
//  Copyright © 2015 Dean Becker. All rights reserved.
//

#ifndef Vector3f_hpp
#define Vector3f_hpp

#include <stdio.h>

class Vector3f
{
public:
    float x, y, z;

    Vector3f();
    Vector3f(float x, float y, float z);

    float dot(Vector3f* otherVec);
};

#endif /* Vector3f_hpp */
