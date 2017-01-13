#include "header/GameEngine.h"



GameEngine * GameEngine::_instance = NULL;

bool GameEngine::_game_stopped = true;

GameEngine::GameEngine()
{
    draw_grid = false;
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
    {
        PrintLog("Try find collision with null user", WARNING_MESSAGE);
        return;
    }

    for (int i = 0; i < _game_objects.size(); i++)
    {
        if (_user && _user->Collision(_game_objects[i]))
        {
            PrintLog("Collision was found", INFO_MESSAGE);
            IGameObject * _objForRemove = _game_objects[i];
            _game_objects.erase(_game_objects.begin() + i);
            _user->IncSize();
            
            SaveDelete(_objForRemove);
        }
    }
}

void GameEngine::RenderScene() 
{   if (draw_grid)
        DrawNet();
    DrawObjects();
}


void GameEngine::AddGameObject(IGameObject * g_object)
{
    PrintLog("AddObject", INFO_MESSAGE);
    if (g_object->GetType() == SNAKE) {
        _user = dynamic_cast<Snake*>(g_object);
        _game_stopped = false;
        PrintLog("New Snake in game", INFO_MESSAGE);
    }
    _game_objects.push_back(g_object);
}


void GameEngine::SendMessage(uint message_type, uint  message_value)
{
    switch (message_type)
    {
        case USER_MOVE:     if (_user)
                                _user->SetDirection(message_value);
                            break;

        case CHANGE_STATE:  _game_stopped = (bool) message_value;
                            break;

        case GRID:          draw_grid = (bool) message_value;
                            break;

        case NEW_GAME:      if(_user == NULL)
                            AddGameObject(new Snake());


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


int GameEngine::GetParam(int param_type)
{
    switch( param_type)
    {
        case GRID:      return (int) draw_grid;
        default:        return (int) -1;
    }
}


GameEngine::~GameEngine()
{
    PrintLog("Remove GameEngine", WARNING_MESSAGE);
    _user = NULL;
    _instance = NULL;
    for (int i = 0; i < _game_objects.size(); i++)
        delete _game_objects[i];

}