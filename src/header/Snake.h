#ifndef _SNAKE_	
#define _SNAKE_

#include <GL/freeglut.h>
#include <cstdio>


#include "util.h"
#include "engine_common.h"

#include "IGameObject.h"


#include <deque>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define SPACE 4

class Snake : public IGameObject 
{
	private:
		std::deque< std::pair<int, int> > _snake;
		int _side;
		
	public:
		Snake();
		~Snake();
		void RenderObject();
		void Move();
		void SetDirection(int direction);
		int  GetType();
		bool Collision(IGameObject *);
		void IncSize();
		
		std::pair<int, int> GetPosition();

};
#endif