//
//  PulseLine.hpp
//  PulseLine1
//
//  Created by Lisa Jamhoury on 10/16/16.
//
//

#pragma once

#include "cinder/Shape2d.h"

class PulseLine {
public:
    
    PulseLine() {}
    PulseLine( cinder::vec2 aLoc, cinder::vec2 aDest );
    
    void step();
    void display();

    cinder::Shape2d mShape2d;
    cinder::vec2 mStartLoc;
    cinder::vec2 mLoc;
    cinder::vec2 mDest;
};