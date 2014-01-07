#include "header/GameEngine.h"

#include "header/util.h"
#include "header/engine_common.h"

#include "header/Snake.h"

GameEngine * GameEngine::_instance = NULL;

GameEngine::GameEngine()
{
	PrintLog("Init timer", INFO_MESSAGE);
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
	for (int i = 0 ; i < _game_objects.size(); i++)
		_game_objects[i]->Move();
}

void GameEngine::DrawObjects()
{
	for (int i = 0 ; i < _game_objects.size(); i++)
		_game_objects[i]->RenderObject();		
}

void GameEngine::RenderScene() 
{
	DrawNet();
	ObjectActions();
	DrawObjects();
}


void GameEngine::AddGameObject(IGameObject * g_object)
{
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
		case KEYBOARD_DOWN: if (_user != NULL)
								_user->SetDirection(message_value);
							break;

	}

}
