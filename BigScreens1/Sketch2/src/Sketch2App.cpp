#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "LeftSensor.hpp"
#include "RightSensor.hpp"
#include "PulseSensor1.hpp"
#include "PulseSensor2.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class Sketch2App : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    
    //void setFrameRate();
    
    
    LeftSensor *mLeftSensor;
    RightSensor *mRightSensor;
    PulseSensor1 *mPulseSensor1;
    PulseSensor2 *mPulseSensor2;
};


void Sketch2App::setup()
{
    //mFbo.bindBuffer();
    gl::clear( Color::black());
    gl::enableAlphaBlending();
    
    
    mLeftSensor = new LeftSensor();
    mRightSensor = new RightSensor();
    mPulseSensor1 = new PulseSensor1();
    mPulseSensor2 = new PulseSensor2();
}

void Sketch2App::mouseDown( MouseEvent event )
{
}

void Sketch2App::update()
{
    mLeftSensor->update();
    mRightSensor->update();
    mPulseSensor1->update();
    mPulseSensor2->update();
}

void Sketch2App::draw()
{
    //gl::color(ColorA( 0.0f, 0.0f, 0.0f, 0.1f));
    mLeftSensor->draw();
    mRightSensor->draw();
    mPulseSensor1->draw();
    mPulseSensor2->draw();
}
CINDER_APP( Sketch2App, RendererGl,
        [&]( App::Settings *settings) {
            settings->setWindowSize(1440, 135);  // 11520, 1080 / 1440, 135
            //settings->setFullScreen(true);
            //settings->setHighDensityDisplayEnabled();

        })