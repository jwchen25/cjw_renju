#include "CJW_UI.h"

CJW_UI::CJW_UI()
{
    //ctor
}

CJW_UI::~CJW_UI()
{
    //dtor
}

void CJW_UI::Welcome_Interface()
{
    system("title ��������Ϸ By CJW ");  //���ñ���
	system("mode con cols=54 lines=20");  //���ô��ڴ�С
	system("color E0");  //������ɫ
	system("cls");  //����
	cout<<endl<<endl;
	cout<<" ���������������������������"<<endl;
	cout<<" ���������������������������"<<endl;
	cout<<" ���                                            ���"<<endl;
	cout<<" ���                                            ���"<<endl;
	cout<<" ���        ��       ӭ       ʹ       ��       ���"<<endl;
	cout<<" ���                                            ���"<<endl;
	cout<<" ���              ��      ��     ��             ���"<<endl;
	cout<<" ���                                            ���"<<endl;
	cout<<" ���                                            ���"<<endl;
	cout<<" ���                                            ���"<<endl;
	cout<<" ���   ����� �¿���(CJW)     ָ����ʦ ������   ���"<<endl;
	cout<<" ���                                            ���"<<endl;
	cout<<" ���                 C++�������                ���"<<endl;
	cout<<" ���                                            ���"<<endl;
	cout<<" ���               �й���ѧԺ��ѧ              ���"<<endl;
	cout<<" ���������������������������"<<endl;
	cout<<" ���������������������������"<<endl;
	cout<<"                     �����������"<<endl;
    getch();
}

int CJW_UI::GameOption_Interface()
{
    system("mode con cols=54 lines=20");  //���ô��ڴ�С
    int input;  //�������
    int option=1;
	while(1)  //ֱ���������һ����ȷ����Ϣ
    {
        system("cls");  //����
        switch(option)  //���������Ϸģʽ��ѡ��
        {
            case 1:
                cout << endl ;
                cout << "                ��     Ϸ     ģ     ʽ" << endl << endl << endl;
                cout << "             �������˶�ս(����ʱ)����" << endl << endl << endl;
                cout << "                   �˻���ս(����ʱ)   " << endl << endl << endl;
                cout << "                    ���˶�ս(��ʱ)   " << endl << endl << endl;
                cout << "                    �˻���ս(��ʱ)   " << endl << endl << endl;
                cout << "                     �ۿ����Զ�ս   " << endl << endl << endl;
                cout << " 1.�����·�����ƶ� 2.���ո��ȷ�� 3.��EXC��ֱ���˳�";
                break;
            case 2:
                cout << endl ;
                cout << "                ��     Ϸ     ģ     ʽ" << endl << endl << endl;
                cout << "                   ���˶�ս(����ʱ)   " << endl << endl << endl;
                cout << "             �����˻���ս(����ʱ)����" << endl << endl << endl;
                cout << "                    ���˶�ս(��ʱ)   " << endl << endl << endl;
                cout << "                    �˻���ս(��ʱ)   " << endl << endl << endl;
                cout << "                     �ۿ����Զ�ս   " << endl << endl << endl;
                cout << " 1.�����·�����ƶ� 2.���ո��ȷ�� 3.��EXC��ֱ���˳�";
                break;
            case 3:
                cout << endl ;
                cout << "                ��     Ϸ     ģ     ʽ" << endl << endl << endl;
                cout << "                   ���˶�ս(����ʱ)   " << endl << endl << endl;
                cout << "                   �˻���ս(����ʱ)   " << endl << endl << endl;
                cout << "              �������˶�ս(��ʱ)����" << endl << endl << endl;
                cout << "                    �˻���ս(��ʱ)   " << endl << endl << endl;
                cout << "                     �ۿ����Զ�ս   " << endl << endl << endl;
                cout << " 1.�����·�����ƶ� 2.���ո��ȷ�� 3.��EXC��ֱ���˳�";
                break;
            case 4:
                cout << endl ;
                cout << "                ��     Ϸ     ģ     ʽ" << endl << endl << endl;
                cout << "                   ���˶�ս(����ʱ)   " << endl << endl << endl;
                cout << "                   �˻���ս(����ʱ)   " << endl << endl << endl;
                cout << "                    ���˶�ս(��ʱ)   " << endl << endl << endl;
                cout << "              �����˻���ս(��ʱ)����" << endl << endl << endl;
                cout << "                     �ۿ����Զ�ս   " << endl << endl << endl;
                cout << " 1.�����·�����ƶ� 2.���ո��ȷ�� 3.��EXC��ֱ���˳�";
                break;
            case 5:
                cout << endl ;
                cout << "                ��     Ϸ     ģ     ʽ" << endl << endl << endl;
                cout << "                   ���˶�ս(����ʱ)   " << endl << endl << endl;
                cout << "                   �˻���ս(����ʱ)   " << endl << endl << endl;
                cout << "                    ���˶�ս(��ʱ)   " << endl << endl << endl;
                cout << "                    �˻���ս(��ʱ)   " << endl << endl << endl;
                cout << "               ����ۿ����Զ�ս����" << endl << endl << endl;
                cout << " 1.�����·�����ƶ� 2.���ո��ȷ�� 3.��EXC��ֱ���˳�";
                break;
        }
		input=getch(); //�ȴ����̰���һ���ַ�
		if(input==27)  //�����ESC���˳�����
        {
			exit(0);
		}
		else if(input==0x20) //����ǿո�
            return option;
		else if(input==0xE0) //������µ��Ƿ������������������룬��һ��Ϊ0xE0��ʾ���µ��ǿ��Ƽ�
        {
            input=getch();   //��õڶ���������Ϣ
			switch(input)    //�жϷ���������ƶ����λ��
			{
				case 0x48:
                    option--; break;
				case 0x50:
				    option++;
			}
			if(option<1)  option=5; //������λ��Խ�����ƶ����Բ�
			if(option>5) option=1;
		}
		else cout <<'\a';  //��������������ʾ
	}
}

int CJW_UI::GameOver_Interface()
{
    system("mode con cols=54 lines=20");  //���ô��ڴ�С
    int input;  //�������
    int option=1;
	while(1)  //ֱ���������һ����ȷ����Ϣ
    {
        system("cls");  //����
        switch(option)  //���������Ϸ�������ѡ��
        {
            case 1:
                cout << endl << endl;
                cout << "               ��     Ϸ     ��     �� ��" << endl << endl ;
                cout << "                  ��      ѡ      ��" << endl << endl << endl;
                cout << "                ���𷵻����˵�����   " << endl << endl << endl<< endl;
                cout << "                       ������Ϸ   " << endl << endl << endl << endl;
                cout << "                       �˳���Ϸ   " << endl << endl << endl << endl;
                cout << " 1.�����·�����ƶ� 2.���ո��ȷ�� 3.��EXC��ֱ���˳�" ;
                break;
            case 2:
                cout << endl << endl;
                cout << "               ��     Ϸ     ��     �� ��" << endl << endl ;
                cout << "                  ��      ѡ      ��" << endl << endl << endl;
                cout << "                      �������˵�      " << endl << endl << endl<< endl;
                cout << "                 ����������Ϸ����   " << endl << endl << endl << endl;
                cout << "                       �˳���Ϸ   " << endl << endl << endl << endl;
                cout << " 1.�����·�����ƶ� 2.���ո��ȷ�� 3.��EXC��ֱ���˳�" ;
                break;
            case 3:
                cout << endl << endl;
                cout << "               ��     Ϸ     ��     �� ��" << endl << endl ;
                cout << "                  ��      ѡ      ��" << endl << endl << endl;
                cout << "                      �������˵�      " << endl << endl << endl<< endl;
                cout << "                       ������Ϸ   " << endl << endl << endl << endl;
                cout << "                 �����˳���Ϸ����   " << endl << endl << endl << endl;
                cout << " 1.�����·�����ƶ� 2.���ո��ȷ�� 3.��EXC��ֱ���˳�" ;
                break;
        }
		input=getch(); //�ȴ����̰���һ���ַ�
		if(input==27)  //�����ESC���˳�����
        {
			exit(0);
		}
		else if(input==0x20) //����ǿո�
            return option;
		else if(input==0xE0) //������µ��Ƿ������������������룬��һ��Ϊ0xE0��ʾ���µ��ǿ��Ƽ�
        {
            input=getch();   //��õڶ���������Ϣ
			switch(input)    //�жϷ���������ƶ����λ��
			{
				case 0x48:
                    option--; break;
				case 0x50:
				    option++; break;
			}
			if(option<1)  option=3; //������λ��Խ�����ƶ����Բ�
			if(option>3)  option=1;
		}
		else cout <<'\a';  //��������������ʾ
	}
}

void CJW_UI::Exit_Interface()
{
    system("mode con cols=54 lines=20");  //���ô��ڴ�С
    system("cls");  //����
    cout << endl << endl<< endl << endl << endl<< endl << endl << endl;
    cout << "          ��    л    ��    ��    ʹ    �� ��" << endl << endl ;
    cout << "                 Thank you for using!";
    cout << endl << endl << endl<< endl << endl << endl << endl << endl;
    Sleep(1500);
}
