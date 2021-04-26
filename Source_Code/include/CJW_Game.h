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
        int Game_Option;  //��Ϸѡ���趨��1Ϊ���˶�ս(����ʱ)��2Ϊ�˻���ս(����ʱ)��3Ϊ���˶�ս(��ʱ)��4Ϊ�˻���ս(��ʱ)��5Ϊ�ۿ����Զ�ս
        void Game_Start();        //��ʼ����������͹�����꣬������Ϸ�տ�ʼ��������Ϸ
        void Game_Running();      //�����û���ѡ�񣬽����Ӧ����Ϸģʽ����������������Ϸ������
        int Game_Judge();        //�ж���Ӯ��ƽ�֡����֣����ص�ǰ�Ծ�״̬���൱������������еĲ���
        void White_Complain();   //�ڷ���������ʱ���׷�����Ͷ�ߺڷ�ʹ�ó�������

    protected:

    private:
        int color;  //��ǰ׼���µ����ӵ���ɫ��1Ϊ���壬-1Ϊ����
        int Game_State;  //��ǰ��Ϸ״̬���������廹����Ӯ�ѷֵ�״������0Ϊʤ��δ�֣�1Ϊ�׷�Ӯ��2Ϊ�ڷ�Ӯ��3Ϊƽ�֣�4Ϊ��ʱ��5Ϊ�ڷ������а׷�Ӯ
        int Cursor_x, Cursor_y;  //�������꣬xΪ������yΪ����
        bool input_over;  //��������Ƿ��������ʱģʽ��
        char Chess_Pieces[15][15];  //��¼����ǵ��������:'0'Ϊ���ӣ�'1'Ϊ������ӡ���'2'Ϊ������ӡ���'3'Ϊ���ӡ�'4'Ϊ���ӡ�
        CJW_Chessboard Game_Board;  //��Ϸ�����̵����
        void People_Input();      //��������壨����������Ϣ��
        void People_Input_Time(); //��������壨����������Ϣ��,��ʱ��
        void Computer_Input();    //�����������
        void Result_Output(int); //����������
        void Player_Hint();       //��Ŀǰ��ҵ���ʾ�������Ǻڷ����ǰ׷����壩
};

#endif // CJW_GAME_H
