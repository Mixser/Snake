#include "header/GlutBackend.h"


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
	#ifndef __APPLE__
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
				  GLUT_ACTION_GLUTMAINLOOP_RETURNS);	
	glEnable(GL_LINE_SMOOTH);
	#endif
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
	#ifndef __APPLE__
 	GLenum res = glewInit();
	if (res != GLEW_OK) {
 		PrintLog("Error ", ERROR_MESSAGE);
 		return false;
 	}
	#endif
 	PrintLog("Window is created ", INFO_MESSAGE);
	return true;						 	
}
