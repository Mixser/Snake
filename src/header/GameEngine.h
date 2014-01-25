#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_


#include <vector>
#include <cstdlib>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Snake.h"

#include "util.h"
#include "engine_common.h"




#define TIMER_STEP 100
#define TIMER_ID 1


class GameEngine
{
	private:

		static GameEngine * _instance ;
		static bool _game_stopped;

		std::vector<IGameObject *> _game_objects;
		Snake * _user;
		bool draw_grid;
		


		GameEngine();
		void DrawNet();
		void ObjectActions();
		void DrawObjects();
		void Collision();
		void SaveDelete(IGameObject * obj);

		void Handler();

		void KeyboardHandler(int key_code);


		static void TimerFunc(int)
		{
			if (_instance != NULL && _instance->_user != NULL) {
				_instance->ObjectActions();
				_instance->Collision();
				glutPostRedisplay();
			}
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
		

		int GetParam(int param_type);

		void SendMessage(uint message_type, uint  message_value);


		~GameEngine();
};

#endif // _GAME_ENGINE_ //