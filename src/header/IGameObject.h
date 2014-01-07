#ifndef _IGAMEOBJECT_
#define _IGAMEOBJECT_


#include <iostream>


class IGameObject 
{
	protected:
		int g_type;
	public:
		virtual void RenderObject() = 0;
		virtual int GetType() = 0;
		virtual void Move() = 0;
		virtual bool Collision(IGameObject *) = 0;
		virtual std::pair<int, int> GetPosition() = 0;
};



#endif // _IGAMEOBJECT_ //