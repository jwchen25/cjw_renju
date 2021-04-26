#include <iostream>
#include "CJW_Chessboard.h"
#include "CJW_Game.h"
#include "CJW_UI.h"
using namespace std;

int main()
{
    CJW_UI ui;
    CJW_Game game;
    int GameOver_Option;
    ui.Welcome_Interface();  //打开软件时的欢迎界面
    option1: game.Game_Option=ui.GameOption_Interface();  //游戏模式选择界面，并得到用户的选择
    option2: game.Game_Start(); game.Game_Running();  //游戏启动，根据用户选择的模式运行游戏
    GameOver_Option=ui.GameOver_Interface();  //游戏结束界面，并得到用户的选择
    if(GameOver_Option==1) goto option1;  //根据用户的选择进行相关操作
    else if(GameOver_Option==2) goto option2;
    ui.Exit_Interface();  //退出软件的界面
    return 0;
}
