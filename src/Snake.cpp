#include "header/Snake.h"

Snake::Snake() 
{
	PrintLog("Init Snake", INFO_MESSAGE);
	for (int i = 0; i < 5; i++)
		_snake.push_front(std::make_pair(i, 0));
	_side = -1;
}	


Snake::~Snake()
{
	PrintLog("Snake was deleted", ERROR_MESSAGE);
}

void Snake::Move()
{
	int y = glutGet(GLUT_WINDOW_HEIGHT) / 20;
	int x = glutGet(GLUT_WINDOW_WIDTH) / 20;

	if (_side == -1)
		return;
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

	newPart.first  = abs(newPart.first % x  + x) % x;
	newPart.second  = abs(newPart.second % y  + y) % y;

	static char _title[15];
	sprintf(_title, "%d x %d", _snake[0].first, _snake[0].second);
	glutSetWindowTitle(_title);
	_snake.push_front(newPart);
}


void Snake::SetDirection(int direction)
{
	std::pair<int, int> newPostion = _snake[0];
	switch (direction)
	{
		case UP: newPostion.second -= 1; break;

		case DOWN: newPostion.second += 1; break;

		case LEFT: newPostion.first -= 1; break;

		case RIGHT: newPostion.first += 1; break;
	}

	for (int i = 0 ; i < _snake.size(); i++)
		if (_snake[i] == newPostion)
			return;

	this->_side = direction;
}


void Snake::RenderObject() 
{
	glLineWidth(2);

	glBegin(GL_QUADS);
	
	for (int i = 0 ; i < _snake.size(); i++)
	{
		int _x = _snake[i].first;
		int _y = _snake[i].second;
		glVertex2i(_x*20     , _y*20 + 10);
		glVertex2i(_x*20 + 10, _y*20 + 20);
		glVertex2i(_x*20 + 20, _y*20 + 10);
		glVertex2i(_x*20 + 10, _y*20);
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
	{
		for (int i = 1; i <_snake.size(); i++)
			if (_snake[0] == _snake[i])
				return true;
		return false;
	} else {
		for (int i = 0; i < _snake.size(); i++)
			if (_snake[i] ==  obj->GetPosition())
				return true;
		return false;
	}	
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

