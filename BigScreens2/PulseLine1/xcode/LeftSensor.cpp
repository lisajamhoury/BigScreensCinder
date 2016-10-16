//
//  LeftSensor.cpp
//  PulseLine1
//
//  Created by Lisa Jamhoury on 10/16/16.
//
//

#include "cinder/app/App.h"
#include "cinder/Rand.h"
#include "LeftSensor.hpp"
#include "PulseLine.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

LeftSensor::LeftSensor() {
    int dest = getWindowWidth()*0.7f;
    float frames = 10800.0;
    float tempVel = dest/frames;
    
//    float height = getWindowHeight();
//    float tempLength = 100;
    
    mStartLoc = vec2( 0, getWindowHeight()/2);
    mLoc = mStartLoc;
    mVel = vec2( tempVel, 0);
    
    //mLineVel = vec2( 0, tempLength );

}

void LeftSensor::update() {
        if (mPulseLines.size() > 0) {
            for (auto line1 = mPulseLines.begin(); line1 != mPulseLines.end(); ++line1) {
            line1->step();
        }
    }
    
    mLoc += mVel;
}

void LeftSensor::draw() {
    gl::color(0.3f, 0.3f, 0.3f);
    mShape2d.moveTo( mStartLoc );
    mShape2d.lineTo( mLoc );
    gl::draw( mShape2d );
    
    for (auto line1 = mPulseLines.begin(); line1 != mPulseLines.end(); ++line1) {
        line1->display();
    }
}

void LeftSensor::onInput () {
    float yDestLength = 40.0f + randFloat(-3, 3);
    //mLineDest = vec2 (mLoc.x, posDestY );
    mPulseLines.push_back( PulseLine( mLoc, vec2( mLoc.x, mLoc.y + yDestLength) ) );
    mPulseLines.push_back( PulseLine( mLoc, vec2(mLoc.x, mLoc.y - yDestLength) ) );
}

