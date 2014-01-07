#include "header/Apple.h"
#include "header/util.h"
#include "header/engine_common.h"

Apple::Apple(int x, int y)
{
	PrintLog("Apple", WARNING_MESSAGE );
	_X = x;
	_Y = y;
}


void Apple::RenderObject()
{
	PrintLog("Render Apple", WARNING_MESSAGE );
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
	return 2;
}

void Apple::Move()
{
	return;
}

bool Apple::Collision(IGameObject * obj)
{
	return false;
}