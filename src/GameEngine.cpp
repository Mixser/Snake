#include "header/GameEngine.h"



GameEngine * GameEngine::_instance = NULL;

bool GameEngine::_game_stopped = true;

GameEngine::GameEngine()
{
	
	PrintLog("Init GameEngine", INFO_MESSAGE);
	glutTimerFunc(TIMER_STEP, TimerFunc, TIMER_ID);	
}

void GameEngine::DrawNet() 
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height =glutGet(GLUT_WINDOW_HEIGHT);
	glBegin(GL_LINES);
		for (int i = 0; i <= height / 20; i++)
		{
			glVertex2i(0, i * 20);
			glVertex2i(width, i * 20);
		}

		for (int i = 0; i <= width / 20; i++)
		{
			glVertex2i(i*20, 0);
			glVertex2i(i*20, height);
		}		
	glEnd();
}

void GameEngine::ObjectActions() 
{
	if (_game_stopped)
		return;
	for (int i = 0 ; i < _game_objects.size(); i++)
		if (_game_objects[i] != 0)
			_game_objects[i]->Move();
}

void GameEngine::DrawObjects()
{
	for (int i = 0 ; i < _game_objects.size(); i++)
		_game_objects[i]->RenderObject();		
}

void GameEngine::Collision()
{
	if (_user == NULL)
		return;
	for (int i = 0; i < _game_objects.size(); i++)
		if ( _user && _user->Collision(_game_objects[i]))
		{
			PrintLog("Collision was found by engine (snake with apple)", INFO_MESSAGE);
			IGameObject * _objForRemove = _game_objects[i];
			_game_objects.erase(_game_objects.begin() + i);
			_user->IncSize();
			SaveDelete(_objForRemove);
		}
}

void GameEngine::RenderScene() 
{
	DrawNet();
	DrawObjects();
}


void GameEngine::AddGameObject(IGameObject * g_object)
{
	PrintLog("AddObject", INFO_MESSAGE);
	if (g_object->GetType() == 1)
		_user = dynamic_cast<Snake*>(g_object);
	_game_objects.push_back(g_object);
}


void GameEngine::SendMessage(uint message_type, uint  message_value)
{
	switch (message_type)
	{
		case SNAKE_TURN: 
							break;

		case KEYBOARD_DOWN: KeyboardHandler(message_value);
							break;

		case STOP_GAME: 	_game_stopped = true;
							break;

		case START_GAME:	_game_stopped = false;
							break;

	}
}

void GameEngine::KeyboardHandler(int key_code)
{
	switch (key_code)
	{
		case UP:
		case DOWN:
		case LEFT:
		case RIGHT:	if (_user != NULL)
						_user->SetDirection(key_code);
					break;
		case SPACE:
					if (_game_stopped && _user == NULL)
					{
						AddGameObject(new Snake());
						_game_stopped = false;
					}
					break;

	}
}




void GameEngine::SaveDelete(IGameObject * obj)
{
	int obj_type = obj->GetType();
	switch (obj_type)
	{

		case SNAKE: _game_stopped = true;
					_user = NULL;
					break;

		case APPLE:	
					break;
	}
	delete obj;
}