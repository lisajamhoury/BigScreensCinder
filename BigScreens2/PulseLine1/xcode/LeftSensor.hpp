//
//  LeftSensor.hpp
//  PulseLine1
//
//  Created by Lisa Jamhoury on 10/16/16.
//
//

#pragma once

#include "cinder/Shape2d.h"
#include "PulseLine.hpp"

class LeftSensor {
public:
    LeftSensor();
    
    void update();
    void draw();
    void onInput();
    
    float frameCt;
    float now_;
    
    std::vector<PulseLine> mPulseLines;
    
    cinder::Shape2d mShape2d;
    
    cinder::vec2 mStartLoc;
    cinder::vec2 mLoc;
    cinder::vec2 mVel;
    cinder::vec2 mLineVel;
};
