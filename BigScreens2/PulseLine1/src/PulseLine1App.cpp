#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Shape2d.h"
#include "LeftSensor.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class PulseLine1App : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    LeftSensor *mLeftSensor;

};

void PulseLine1App::setup()
{
//    For Full Screen
//    getWindow()->setPos(0, 0);
//    getWindow()->setBorderless();
//    getWindow()->setAlwaysOnTop();
//    getWindow()->spanAllDisplays();
    
    mLeftSensor = new LeftSensor();
    
}

void PulseLine1App::mouseDown( MouseEvent event )
{
    mLeftSensor->onInput();
}

void PulseLine1App::update()
{
    mLeftSensor->update();
}

void PulseLine1App::draw()
{
	gl::clear( Color( 1.0f, 1.0f, 1.0f ) );
    mLeftSensor->draw();

}

CINDER_APP( PulseLine1App, RendererGl,
           [&]( App::Settings *settings) {
               settings->setWindowSize(1440, 135);  // 11520, 1080 / 1440, 135
               //settings->setFullScreen(true);
               //settings->setHighDensityDisplayEnabled();
           })

