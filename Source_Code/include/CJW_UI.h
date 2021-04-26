#ifndef CJW_UI_H
#define CJW_UI_H
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class CJW_UI
{
    public:
        CJW_UI();
        virtual ~CJW_UI();
        void Welcome_Interface();  //软件刚打开时的用户欢迎界面
        int GameOption_Interface();  //游戏模式的选择界面
        int GameOver_Interface();  //游戏结束后跳转的界面
        void Exit_Interface();  //软件的退出界面

    protected:

    private:
};

#endif // CJW_UI_H
