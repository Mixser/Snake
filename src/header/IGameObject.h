#ifndef _IGAMEOBJECT_
#define _IGAMEOBJECT_

class IGameObject 
{
	protected:
		int g_type;
		int _X, _Y;
	public:
		virtual void RenderObject() = 0;
		virtual int GetType() = 0;
		virtual void Move() = 0;
		//virtual bool Collision() = 0;		
};



#endif // _IGAMEOBJECT_ //