#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#include "IGameObject.h"
#include "Snake.h"

#include <vector>
#include <cstdlib>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


#define TIMER_STEP 100
#define TIMER_ID 1


class GameEngine
{
	private:
		static GameEngine * _instance ;
		std::vector<IGameObject *> _game_objects;
		Snake * _user;
		GameEngine();
		void DrawNet();
		void ObjectActions();
		void DrawObjects();


		static void TimerFunc(int)
		{
			if (_instance != NULL)
				glutPostRedisplay();
			glutTimerFunc(TIMER_STEP, TimerFunc, TIMER_ID);
		}		


	public:
		static GameEngine * GetInstance()
		{
			if (_instance == NULL)
				_instance = new GameEngine();
			return _instance;
		}		
		void RenderScene();
		void AddGameObject(IGameObject * g_object);
		

		void SendMessage(uint message_type, uint  message_value);
};

#endif // _GAME_ENGINE_ //