#ifndef _ICALLBACK_
#define _ICALLBACK_

class ICallback 
{
	public:
		virtual void SpecialKeyboard(int Key, int x, int y) = 0;
		virtual void Keyboard(unsigned char key, int x, int y) = 0;
		virtual void Mouse(int Button, int state, int x, int y) = 0;
		virtual void RenderScene() = 0;
		virtual void Idle() = 0;
		virtual void Reshape(int, int) = 0;
};


#endif // _ICALLBACK_ //