#ifndef CJW_GAME_H
#define CJW_GAME_H
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <thread>
#include <windows.h>
#include "CJW_Chessboard.h"
#include "CJW_AI.h"
#include "CJW_Forbidden.h"
#include "CJW_Timer.h"
using namespace std;

class CJW_Game
{
    public:
        CJW_Game();
        virtual ~CJW_Game();
        int Game_Option;  //游戏选项设定：1为人人对战(不计时)，2为人机对战(不计时)，3为人人对战(计时)，4为人机对战(计时)，5为观看电脑对战
        void Game_Start();        //初始化落子情况和光标坐标，用于游戏刚开始或重新游戏
        void Game_Running();      //根据用户的选择，进入对应的游戏模式，并控制五子棋游戏的运行
        int Game_Judge();        //判断输赢、平局、禁手，返回当前对局状态，相当于五子棋比赛中的裁判
        void White_Complain();   //黑方连成五子时，白方可以投诉黑方使用长连禁手

    protected:

    private:
        int color;  //当前准备下的棋子的颜色，1为白棋，-1为黑棋
        int Game_State;  //当前游戏状态（正在下棋还是输赢已分等状况）：0为胜负未分，1为白方赢，2为黑方赢，3为平局，4为超时，5为黑方禁手判白方赢
        int Cursor_x, Cursor_y;  //光标的坐标，x为行数，y为列数
        bool input_over;  //玩家输入是否结束（计时模式）
        char Chess_Pieces[15][15];  //记录玩家们的落子情况:'0'为无子，'1'为刚落白子△，'2'为刚落黑子▲，'3'为白子○，'4'为黑子●
        CJW_Chessboard Game_Board;  //游戏中棋盘的输出
        void People_Input();      //人玩家下棋（输入下棋信息）
        void People_Input_Time(); //人玩家下棋（输入下棋信息）,计时版
        void Computer_Input();    //电脑玩家下棋
        void Result_Output(int); //输出比赛结果
        void Player_Hint();       //对目前玩家的提示（现在是黑方还是白方下棋）
};

#endif // CJW_GAME_H
