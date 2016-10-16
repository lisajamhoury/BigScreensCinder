//
//  PulseLine.cpp
//  Sketch2
//
//  Created by Lisa Jamhoury on 10/13/16.
//
//

#include "cinder/app/App.h"
#include "PulseLine.hpp"

using namespace ci;

PulseLine::PulseLine(vec2 aLoc, vec2 aVel) {
    mLoc = aLoc;
    mVel = aVel;
}

void PulseLine::step() {
    //mLoc.y+=.01;
    mLoc += mVel;
}

void PulseLine::display() {
    gl::color(255, 255, 255);
    gl::drawSolidCircle(mLoc, 1);
}