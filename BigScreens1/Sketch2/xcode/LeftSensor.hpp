//
//  LeftSensor.hpp
//  Sketch2
//
//  Created by Lisa Jamhoury on 10/13/16.
//
//

#pragma once

class LeftSensor {
public:
    LeftSensor();
    
    void update();
    void draw();
    
    cinder::vec2 mLoc;
    cinder::vec2 mVel;
    
    int frameCt;
};
