//
//  RightSensor.cpp
//  Sketch2
//
//  Created by Lisa Jamhoury on 10/13/16.
//
//

#include "cinder/app/App.h"
#include "RightSensor.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

RightSensor::RightSensor() {
    int dest = getWindowWidth()/2;
    float frames = 10800.0;
    float tempVel = dest/frames;
    
    drawMark = false;
    
    mLoc = vec2( getWindowWidth(), getWindowHeight()/2);
    mVel = vec2( -tempVel, 0);
}

void RightSensor::update() {
    frameCt = getElapsedFrames();
    if (frameCt % 180 == 0) {
        drawMark = true;
    } else {
        drawMark = false;
    }
    mLoc += mVel;
}

void RightSensor::draw() {
    int rad = randInt(20);
    
    if (drawMark) {
        gl::color(ColorA(255, 255, 255, 0.5f));
        gl::drawSolidCircle(mLoc, rad);
    }
}
