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
	switch (key) 
	{
		case GLUT_KEY_UP: 		    p_engine->SendMessage(USER_MOVE, UP);
						    	    break;	

		case GLUT_KEY_DOWN: 	    p_engine->SendMessage(USER_MOVE, DOWN);
						    	    break;

		case GLUT_KEY_LEFT: 	    p_engine->SendMessage(USER_MOVE, LEFT);
						  		    break;

		case GLUT_KEY_RIGHT:	    p_engine->SendMessage(USER_MOVE, RIGHT);
						  		    break;

		case GLUT_KEY_PAGE_DOWN:    p_engine->SendMessage(GRID, !p_engine->GetParam(GRID));
								    return;

		case 27:					exit(0);
									return;

		case GLUT_KEY_SPACE:	    p_engine->SendMessage(NEW_GAME, 0);
								    break;

		default:				
									break;

	}
}

void GameBase::Reshape(int width, int height) 
{
	p_engine->SendMessage(CHANGE_STATE, STOP);
	glLoadIdentity();
    gluOrtho2D(0, width, height, 0);	
    glViewport(viewport_x, viewport_y,  width,  height);
    p_engine->SendMessage(CHANGE_STATE, PLAY);
 
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
	p_engine->AddGameObject( new Snake() );
	glutTimerFunc(10, SpawnFruit, 2);
	return true;
}


GameBase::~GameBase()
{
	PrintLog("Remove GameBase", INFO_MESSAGE);
	delete p_engine;
}