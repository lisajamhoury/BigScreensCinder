//
//  PulseSensor1.hpp
//  Sketch2
//
//  Created by Lisa Jamhoury on 10/13/16.
//
//

#pragma once

#include "PulseLine.hpp"

class PulseSensor1 {
public:
    PulseSensor1();
    
    void update();
    void draw();
    
    float frameCt;
    float now_;
    
    bool moving;
    
    std::vector<PulseLine> mPulseLines;
    size_t mNumPLines;
    
    cinder::vec2 mLoc;
    cinder::vec2 mVel;
    cinder::vec2 lineVel;
};
