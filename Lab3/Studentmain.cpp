#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define GLX_GLXEXT_LEGACY //Must be declared so that our local glxext.h is picked up, rather than the system one


//#include <windows.h>
#include "GameConstants.h"
#include "windowOGL.h"
#include "cWNDManager.h"
#include "cColours.h"
#include "cShapes.h"
#include "cPyramid.h"
#include "cCube.h"
#include "cSphere.h"


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR cmdLine,
                   int cmdShow)
{

    //Set our window settings
    const int windowWidth = 1024;
    const int windowHeight = 768;
    const int windowBPP = 16;



    //This is our window
	static cWNDManager* pgmWNDMgr = cWNDManager::getInstance();

    //The example OpenGL code
    windowOGL theOGLWnd;

    //Attach our example to our window
	pgmWNDMgr->attachOGLWnd(&theOGLWnd);

	// Sphere
	cSphere theEarth(3,30,30);
	cSphere theMoon(1, 20, 20);

    //Attempt to create the window
	if (!pgmWNDMgr->createWND(windowWidth, windowHeight, windowBPP))
    {
        //If it fails

        MessageBox(NULL, "Unable to create the OpenGL Window", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
        return 1;
    }

	if (!theOGLWnd.initOGL()) //Initialize our example
    {
        MessageBox(NULL, "Could not initialize the application", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
        return 1;
    }

	// Crate Texture map
	cTexture earthTexture;
	earthTexture.createTexture("Images/Earth.png");
	cTexture moonTexture;
	moonTexture.createTexture("Images/Moon.png");

	theEarth.initialise(earthTexture.getTexture(), glm::vec3(0, 0, 20), glm::vec3(0, 0, 0));
	theEarth.setRotAngle(glm::vec3(90.0f, 0.0f, 0.0f));
	float earthRotSpeed = 25.0f;

	theMoon.initialise(moonTexture.getTexture(), glm::vec3(0, 5, 8), glm::vec3(0, 0, 0));
	float moonRotSpeed = 25.0f;
	theMoon.setRotAngle(glm::vec3(90.0f, 0.0f, 0.0f));

    //This is the mainloop, we render frames until isRunning returns false
	while (pgmWNDMgr->isWNDRunning())
    {
		pgmWNDMgr->processWNDEvents(); //Process any window events

        //We get the time that passed since the last frame
		float elapsedTime = pgmWNDMgr->getElapsedSeconds();
		
		// Lab code goes here
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		theOGLWnd.initOGL();
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -60.0f);

		theEarth.setRotAngle(glm::vec3(theEarth.getRotAngle().x, theEarth.getRotAngle().y, theEarth.getRotAngle().z + earthRotSpeed*elapsedTime));
		theEarth.prepare(theEarth.getRotAngle()); //Do any pre-rendering logic
		theEarth.render(theEarth.getRotAngle()); //Render the scene

		glPopMatrix();
		glPushMatrix();
		
		glTranslatef(0.0f, 0.0f, -40.0f);

		theMoon.setRotAngle(glm::vec3(theMoon.getRotAngle().x, theMoon.getRotAngle().y, theMoon.getRotAngle().z + moonRotSpeed*elapsedTime));
		theMoon.prepare(theMoon.getRotAngle());
		theMoon.render(theMoon.getRotAngle());
		pgmWNDMgr->swapBuffers();
		glPopMatrix();
    }

	theOGLWnd.shutdown(); //Free any resources
	pgmWNDMgr->destroyWND(); //Destroy the program window

    return 0; //Return success
}
