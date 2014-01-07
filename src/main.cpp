#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "header/GlutBackend.h"
#include "header/GameBase.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PROJECT_NAME "Application"



int main(int argc, char ** argv) {
	GameBase * pApp = new GameBase();

	GLUTBackendInit(argc, argv);
	
	if (!GLUTBackendCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 32, false, PROJECT_NAME))
		return 1;

	if (!pApp->Init())		
		return 1;
	
	GLUTBackendRun(pApp);

	delete pApp;

	return 0;
}