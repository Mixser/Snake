#ifndef _GAMEBASE_ 
#define _GAMEBASE_
#include "ICallback.h"
#include "GameEngine.h"
class GameBase : public ICallback
{
	private:
		GameEngine * p_engine;
		int viewport_x, viewport_y;
		static GameBase * p_base;
		GameBase();
	public:
		static GameBase * GetInstance() 
		{
			if (p_base == NULL)
				p_base = new GameBase();
			return p_base;
		}



		virtual void SpecialKeyboard(int Key, int x, int y);
		virtual void Keyboard(unsigned char key, int x, int y);
		virtual void Mouse(int Button, int state, int x, int y);
		virtual void RenderScene();
		virtual void Idle();
		virtual void Reshape(int, int);

		bool Init();

		friend void SpawnFruit(int timer_id);
		virtual ~GameBase();
};

#endif //_GAMEBASE_//