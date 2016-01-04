//
//  IRenderable.hpp
//  CrappyBird
//
//  Created by Dean Becker on 03/01/2016.
//  Copyright � 2016 Dean Becker. All rights reserved.
//

#ifndef IRenderable_hpp
#define IRenderable_hpp

class IRenderable
{
public:
    virtual ~IRenderable();
    
	virtual void render() = 0;
	virtual void update() = 0;
};

#endif /* IRenderable_hpp */