//
//  LeftSensor.cpp
//  IACTest
//
//  Created by Lisa Jamhoury on 10/14/16.
//
//

#include "cinder/app/App.h"
#include "LeftSensor.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

LeftSensor::LeftSensor() {
    int dest = getWindowWidth()/2;
    float frames = 10800.0;
    float tempVel = dest/frames;
    
    mLoc = vec2( 0, getWindowHeight()/2);
    mVel = vec2( tempVel, 0);
}

void LeftSensor::update() {
    mLoc += mVel;
}

void LeftSensor::draw() {
    int rad = 10;
    
    gl::color(0.68f, 0.68f, 0.68f);
    gl::drawSolidCircle(mLoc, rad);

}
