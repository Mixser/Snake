#ifndef _GLUT_BACKEND_
#define _GLUT_BACKEND_

#include <cstdio>
#include <GL/glew.h>
#include <GL/freeglut.h>




#include "ICallback.h"

#include "engine_common.h"
#include "util.h"

void GLUTBackendInit(int argc, char ** argv);


bool GLUTBackendCreateWindow(unsigned int width, unsigned int height,
							 unsigned int bpp, bool isFullScreen,
							 const char * pTitle);


void GLUTBackendRun(ICallback * pCallback);


#endif //_GLUT_BACKEND_//