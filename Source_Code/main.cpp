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
    ui.Welcome_Interface();  //�����ʱ�Ļ�ӭ����
    option1: game.Game_Option=ui.GameOption_Interface();  //��Ϸģʽѡ����棬���õ��û���ѡ��
    option2: game.Game_Start(); game.Game_Running();  //��Ϸ�����������û�ѡ���ģʽ������Ϸ
    GameOver_Option=ui.GameOver_Interface();  //��Ϸ�������棬���õ��û���ѡ��
    if(GameOver_Option==1) goto option1;  //�����û���ѡ�������ز���
    else if(GameOver_Option==2) goto option2;
    ui.Exit_Interface();  //�˳�����Ľ���
    return 0;
}
