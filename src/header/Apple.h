#ifndef _APPLE_


#define _APPLE_


#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "IGameObject.h"

#include "util.h"
#include "engine_common.h"


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