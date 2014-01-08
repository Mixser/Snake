#include "header/GameBase.h"



#define GLUT_KEY_SPACE 32


GameBase * GameBase::p_base = NULL;

GameBase::GameBase()
{

}


void GameBase::SpecialKeyboard(int key, int x, int y)
{
	PrintLog("Special key down", INFO_MESSAGE);
}

void GameBase::Mouse(int button,int state ,int x, int y) 
{
	PrintLog("Mouse is active", INFO_MESSAGE);

}

void GameBase::Keyboard(unsigned char key, int x, int y)
{
	int _message = -1;
	switch (key) 
	{
		case GLUT_KEY_UP: 
								_message = UP;
						    	break;	
		case GLUT_KEY_DOWN: 	
								_message = DOWN;
						    	break;
		case GLUT_KEY_LEFT: 	
								_message = LEFT;
						  		break;
		case GLUT_KEY_RIGHT:	
								_message = RIGHT;
						  		break;
		case GLUT_KEY_SPACE:
								_message = SPACE;
								break;
		case GLUT_KEY_PAGE_DOWN: 
								p_engine->SendMessage(GRID, 0);
								return;
		default:				
								break;


	}
	p_engine->SendMessage(KEYBOARD_DOWN, _message);
}

void GameBase::Reshape(int width, int height) 
{
	p_engine->SendMessage(STOP_GAME, 0);
	glLoadIdentity();
    gluOrtho2D(0, width, height, 0);	
    glViewport(viewport_x, viewport_y,  width,  height);
    p_engine->SendMessage(START_GAME, 0);
 
}



void GameBase::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	p_engine->RenderScene();
	glutSwapBuffers();
}

void GameBase::Idle()
{
	glutPostRedisplay();	
}


void SpawnFruit(int timer_id)
{
	GameBase * p = GameBase::GetInstance();
	p->p_engine->AddGameObject(new Apple(rand() % 40, rand() % 30));
	glutTimerFunc(2000, SpawnFruit, timer_id);
}

bool GameBase::Init()
{
	viewport_x = 0;
	viewport_y = 0;
	PrintLog("Init game base", INFO_MESSAGE);
	p_engine = GameEngine::GetInstance();
	p_engine->AddGameObject( new Snake());
	glutTimerFunc(10, SpawnFruit, 2);
	return true;
}


GameBase::~GameBase()
{
	PrintLog("Remove GameBase", INFO_MESSAGE);
}