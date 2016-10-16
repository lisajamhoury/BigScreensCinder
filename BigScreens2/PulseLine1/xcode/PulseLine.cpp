//
//  PulseLine.cpp
//  PulseLine1
//
//  Created by Lisa Jamhoury on 10/16/16.
//
//

#include "cinder/app/App.h"
#include "PulseLine.hpp"

using namespace ci;

PulseLine::PulseLine(vec2 aLoc, vec2 aVel) {
    mStartLoc = aLoc;
    mLoc = mStartLoc;
    mVel = aVel;
}

void PulseLine::step() {
    mLoc += mVel;
}

void PulseLine::display() {

    gl::color(0.3f, 0.3f, 0.3f);
    mShape2d.moveTo( mStartLoc );
    mShape2d.lineTo( mLoc );
    gl::draw( mShape2d );
}