//
//  LeftSensor.cpp
//  Sketch2
//
//  Created by Lisa Jamhoury on 10/13/16.
//
//

#include "cinder/app/App.h"
#include "LeftSensor.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

LeftSensor::LeftSensor() {
//    int dest = getWindowWidth()/2;
//    float frames = 10800.0;
//    float tempVel = dest/frames;
    
    mLoc = vec2( 0, getWindowHeight()/2);
    //mVel = vec2( 0, 0);
}

void LeftSensor::update() {
    float r = randFloat(1);
    frameCt = getElapsedFrames();

    if (frameCt % 15 == 0) {
        if (r < 0.4) {
            mLoc.x+=5;
        } else if (r < 0.6) {
            mLoc.x-=5;
        } else if (r < 0.8) {
            mLoc.y+=5;
        } else {
            mLoc.y-=5;
        }
    }
}

void LeftSensor::draw() {
    int rad = 1;
    
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(mLoc, rad);
    
}
