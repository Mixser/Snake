#ifndef _APPLE_


#define _APPLE_

#include "IGameObject.h"

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>


class Apple : public IGameObject
{
	private:
		int _X;
		int _Y;
		virtual void Move();
	public:

		Apple(int x, int y);

		virtual void RenderObject();
		virtual int  GetType();
		
		virtual bool Collision(IGameObject *);
		virtual std::pair<int, int> GetPosition();
};

#endif