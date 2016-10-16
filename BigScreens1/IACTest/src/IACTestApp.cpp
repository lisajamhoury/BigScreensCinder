#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "LeftSensor.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class IACTestApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    LeftSensor *mLeftSensor;
};

void IACTestApp::setup()
{
    getWindow()->setPos(0, 0);
    getWindow()->setBorderless();
    getWindow()->setAlwaysOnTop();
    getWindow()->spanAllDisplays();
    
    mLeftSensor = new LeftSensor();

}

void IACTestApp::mouseDown( MouseEvent event )
{
}

void IACTestApp::update()
{
    mLeftSensor->update();
}

void IACTestApp::draw()
{
    gl::clear( Color::gray( 0.1f ) );
    mLeftSensor->draw();
}

CINDER_APP( IACTestApp, RendererGl )
