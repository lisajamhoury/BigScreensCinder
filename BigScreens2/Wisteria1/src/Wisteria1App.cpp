#include "cinder/app/App.h"
#include "cinder/cairo/Cairo.h"
#include "cinder/Rand.h"
#include "cinder/ImageIo.h"
#include "cinder/Utilities.h"
using namespace ci;
using namespace ci::app;

#include <vector>
using std::vector;

#include "Branch.hpp"


int MAX_BRANCHES = 40;
int IDLE_RESTART_FRAMES = 72;
const int WIDTH = 1440;
const int HEIGHT = 135;

class Wisteria1App : public App {
public:
    static void prepareSettings( Settings *settings );
    void setup() override;
    
    void renderScene( cairo::Context &ctx );
    void keyDown( KeyEvent event ) override;
    void mouseDown( MouseEvent event ) override;
    
    void update() override;
    void draw() override;
    
    cairo::SurfaceImage		mOffscreenBuffer;
    cairo::Context			mOffscreenContext;
    
    vector<Branch>	mBlossoms;
    bool			mIsIdle; // are the blossoms all done growing?
    int				mIdleFrames;
};

void Wisteria1App::prepareSettings( Settings *settings )
{
    settings->setWindowSize( WIDTH, HEIGHT );
    settings->setResizable( false );
}

void Wisteria1App::setup()
{
    // allocate our offscreen buffer
    mOffscreenBuffer = cairo::SurfaceImage( WIDTH, HEIGHT, false );
    mOffscreenContext = cairo::Context( mOffscreenBuffer );
    
    // fill the buffer with gray
    //mOffscreenContext.setSourceRgb( 0.23f, 0.23f, 0.23f );
    mOffscreenContext.setSourceRgb(1.0f, 1.0f, 1.0f); //.98f, .90f, .66f
    mOffscreenContext.paint();
    
    // Let the Branches know how big our windows is
    Branch::setWindowSize( WIDTH, HEIGHT );
    
    // Create some starting blossoms
    //mBlossoms.push_back( Branch( vec2( WIDTH - 50, 50 ), 0.619444444f, 0 ) );
    //mBlossoms.push_back( Branch( vec2( 60, HEIGHT - 60 ), 0.905f, 180 ) );
    //mBlossoms.push_back( Branch( vec2( WIDTH / 2, HEIGHT / 2 ), 0.105555556f, 320 ) );
    
    mIsIdle = false;
    mIdleFrames = 0;
}

void Wisteria1App::renderScene( cairo::Context &ctx )
{
    for( vector<Branch>::iterator blossomIt = mBlossoms.begin(); blossomIt != mBlossoms.end(); ++blossomIt )
        blossomIt->draw( ctx );
}

void Wisteria1App::keyDown( KeyEvent event )
{
    switch( event.getChar() ) {
        case 'p':
            writeImage( getHomeDirectory() / "wisteriaShot.png", copyWindowSurface() );
            break;
    }
}

void Wisteria1App::mouseDown( MouseEvent event )
{
    mBlossoms.push_back( Branch( event.getPos(), Branch::randomHue(), 0 ) );
}

void Wisteria1App::update()
{
    // Iterate all the blossoms, update each one and notice if they are all idle
    bool isIdle = true;
    for( vector<Branch>::iterator blossomIt = mBlossoms.begin(); blossomIt != mBlossoms.end(); ++blossomIt ) {
        blossomIt->update();
        if( blossomIt->isAlive() )
            isIdle = false;
    }
    
    if( isIdle && ( ! mIsIdle ) ) {
        mIsIdle = true;  // first frame of idleness
        mIdleFrames = 0;
    }
//    else if( isIdle ) { // the blossoms have all not changed in a while, let's clear them out and put up some new ones
//        if( mIdleFrames++ > IDLE_RESTART_FRAMES ) {
//            // clear the context
//            //mOffscreenContext.setSourceRgb( 0.23f, 0.23f, 0.23f );
//            mOffscreenContext.setSourceRgb(1, 1, 1);
//            mOffscreenContext.paint();
//            
//            mBlossoms.clear();
//            mBlossoms.push_back( Branch( vec2( Rand::randFloat( (float)WIDTH ), Rand::randFloat( (float)HEIGHT ) ), Branch::randomHue(), 0 ) );
//            mBlossoms.push_back( Branch( vec2( Rand::randFloat( (float)WIDTH ), Rand::randFloat( (float)HEIGHT ) ), Branch::randomHue(), 180 ) );
//            mBlossoms.push_back( Branch( vec2( Rand::randFloat( (float)WIDTH ), Rand::randFloat( (float)HEIGHT ) ), Branch::randomHue(), 320 ) );
//            
//            mIsIdle = false;
//        }
//    }
}

void Wisteria1App::draw()
{
    cairo::Context ctx( cairo::createWindowSurface() );
    renderScene( mOffscreenContext );
    ctx.copySurface( mOffscreenBuffer, mOffscreenBuffer.getBounds() );
}

CINDER_APP( Wisteria1App, Renderer2d, Wisteria1App::prepareSettings )