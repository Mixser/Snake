#include <cstdio>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "header/ICallback.h"


#include "header/util.h"
#include "header/engine_common.h"


static ICallback * s_callback = NULL;


static void RenderScene() 
{
	s_callback->RenderScene();
}

static void Idle() 
{
	s_callback->Idle();
}

static void SpecialKeyboard(int key, int x, int y)
{
	s_callback->Keyboard(key, x, y);
}

static void Keyboard(unsigned char key, int x, int y)
{
	s_callback->Keyboard(key, x, y);
}

static void Mouse(int Button, int state, int x, int y)
{
	s_callback->Mouse(Button,state, x, y);
}

static void Reshape(int width, int height)
{
	s_callback->Reshape(width, height);
}




static void GlutInitCallbacks() 
{
	
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(Reshape);
	glutSpecialFunc(SpecialKeyboard);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);
	glutIdleFunc(Idle);
}

void GLUTBackendInit(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
				  GLUT_ACTION_GLUTMAINLOOP_RETURNS);	
	glEnable(GL_LINE_SMOOTH);
}

void GLUTBackendRun(ICallback * pCallback)
{
	if (!pCallback) {
		PrintLog("Not callbacks functuons", ERROR_MESSAGE);
		return;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	s_callback = pCallback;

	GlutInitCallbacks();
	glutMainLoop();
}

bool GLUTBackendCreateWindow(unsigned int width, unsigned int height,
							 unsigned int bpp, bool isFullScreen,
							 const char * pTitle)
{
 	glutInitWindowSize(width, height);
 	glutCreateWindow(pTitle);

 	GLenum res = glewInit();
	if (res != GLEW_OK) {
 		PrintLog("Error ", ERROR_MESSAGE);
 		return false;
 	}
 	PrintLog("Window is created ", INFO_MESSAGE);
	return true;						 	
}
