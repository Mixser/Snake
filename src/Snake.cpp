#include "header/Snake.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "header/util.h"
#include "header/engine_common.h"
#include <cstdio>
Snake::Snake() 
{
	for (int i = 0; i < 5; i++)
		_snake.push_front(std::make_pair(i, 0));
	_side = -1;
}	

void Snake::Move()
{

	if (_side == -1)
		return;
	PrintLog("MOVE", WARNING_MESSAGE );
	std::pair<int, int> newPart = _snake.front();
	_snake.pop_back();
	switch (_side)
	{

		case UP: 		newPart.second -=1;
						break;
		case RIGHT: 	newPart.first += 1;
						break;
		case DOWN:		newPart.second += 1;
						break;
		case LEFT:		newPart.first -= 1;
						break;
		default: 
						break;
	}
	_snake.push_front(newPart);
}


void Snake::SetDirection(int direction)
{
	if (direction != -1 && 
		  (direction + _side != 2) &&
			 (direction + _side != 4))
		this->_side = direction;
}


void Snake::RenderObject() 
{
	PrintLog("Render snake", WARNING_MESSAGE );
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	
	for (int i = 0 ; i < _snake.size(); i++)
	{
		int _x = _snake[i].first;
		int _y = _snake[i].second;
		glVertex2i(_x*20 + 10, _y*20 + 10);
	}
	glEnd();
	glLineWidth(1);
}	


int Snake::GetType()
{
	return 1;
}

bool Snake::Collision(IGameObject * obj)
{
	if (obj->GetType() == 1)
		return false;
	for (int i = 0; i < _snake.size(); i++)
		if (_snake[i] ==  obj->GetPosition())
			return true;
	return false;
}


std::pair<int, int> Snake::GetPosition()
{
	return std::make_pair(-1, -1);
}


void Snake::IncSize()
{
	std::pair<int, int> newElem = _snake.back();
	_snake.push_back(newElem);
}

