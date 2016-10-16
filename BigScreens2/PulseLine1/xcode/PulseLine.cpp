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
using namespace::std;

PulseLine::PulseLine(vec2 aLoc, vec2 aDest) {
    mStartLoc = aLoc;
    //mLoc = mStartLoc;
    mDest = aDest;
}

void PulseLine::step() {
    
}

void PulseLine::display() {

    gl::color(0.3f, 0.3f, 0.3f);
    mShape2d.moveTo( mStartLoc );
    mShape2d.lineTo( mDest );
    gl::draw( mShape2d );
}