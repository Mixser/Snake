#include "header/Apple.h"


Apple::Apple(int x, int y)
{
	_X = x;
	_Y = y;
}
Apple::~Apple()
{	
	PrintLog("Apple has been deleted", WARNING_MESSAGE);
}


void Apple::RenderObject()
{
	glBegin(GL_TRIANGLES);
		glVertex2i(_X*20, _Y*20);
		glVertex2i((_X+1)*20, _Y*20);
		glVertex2i(_X*20 + 10, (_Y+1)*20);
	glEnd();
}


std::pair<int, int> Apple::GetPosition() 
{
	return std::make_pair(_X, _Y);
}


int Apple::GetType() 
{
	return APPLE;
}

void Apple::Move()
{
	return;
}

bool Apple::Collision(IGameObject * obj)
{
	return false;
}