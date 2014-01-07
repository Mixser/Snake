#ifndef _GLUT_BACKEND_
#define _GLUT_BACKEND_

#include "ICallback.h"

void GLUTBackendInit(int argc, char ** argv);
bool GLUTBackendCreateWindow(unsigned int width, unsigned int height,
							 unsigned int bpp, bool isFullScreen,
							 const char * pTitle);
void GLUTBackendRun(ICallback * pCallback);
#endif //_GLUT_BACKEND_//