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
        void Welcome_Interface();  //����մ�ʱ���û���ӭ����
        int GameOption_Interface();  //��Ϸģʽ��ѡ�����
        int GameOver_Interface();  //��Ϸ��������ת�Ľ���
        void Exit_Interface();  //������˳�����

    protected:

    private:
};

#endif // CJW_UI_H
