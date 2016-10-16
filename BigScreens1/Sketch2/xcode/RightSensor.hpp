//
//  RightSensor.hpp
//  Sketch2
//
//  Created by Lisa Jamhoury on 10/13/16.
//
//

#pragma once

class RightSensor {
public:
    RightSensor();
    
    void update();
    void draw();
    
    int frameCt;
    bool drawMark;
    
    cinder::vec2 mLoc;
    cinder::vec2 mVel;
};