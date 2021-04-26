#include "CJW_Game.h"


CJW_Game::CJW_Game()
{
    Game_Option=1; //Ĭ����Ϸѡ��Ϊ���˶�ս
    Game_State=0;  //��Ӯδ�֣���������
    Cursor_x=7;  //���������λ��
    Cursor_y=7;
    color=-1;  //1Ϊ���壬-1Ϊ���壬Ĭ�Ϻڷ�����
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++) Chess_Pieces[i][j]='0';
}

CJW_Game::~CJW_Game()
{
    //dtor
}

void CJW_Game::Game_Start()
{
    color=-1;  //Ĭ�Ϻڷ�����
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++) Chess_Pieces[i][j]='0';
    Game_State=0;  //��Ӯδ�֣���������
    Cursor_x=7;  //���������λ��
    Cursor_y=7;
}

void CJW_Game::Game_Running()
{
    system("mode con cols=62 lines=35");  //���ô��ڴ�С
    //����Ϸѡ��Ϊ���˶�ս(����ʱ)����ʼ���˶�ս(����ʱ)
    if(Game_Option==1)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Player_Hint();  //��ʾĿǰ�Ǻڷ����ǰ׷�����
            People_Input();  //����������
            system("cls");  //����
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //��ӡ���µ�����
            Game_State+=Game_Judge();    //��ñ�����Ӯ����Ϣ
            if(Game_State!=0) break;  //�����������˳�ѭ��
            color=-color;   //�ڰ׷��������壨ÿ��һ��ֻ����һ�����ӣ�
        }
        White_Complain();  //�ڷ���������ʱ���׷�����Ͷ�ߺڷ�ʹ�ó�������
        Result_Output(Game_State);  //����������
    }
    //����Ϸѡ��Ϊ�˻���ս(����ʱ)����ʼ�˻���ս(����ʱ)
    else if(Game_Option==2)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Computer_Input();
            system("cls");  //����
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);//��ӡ���µ�����
            Game_State=+Game_Judge();    //��ñ�����Ӯ����Ϣ
            if(Game_State!=0) break;  //�����������˳�ѭ��
            color=-color;   //�ڰ׷��������壨һ��ֻ����һ�����ӣ�
            Player_Hint();  //��ʾĿǰ�Ǻڷ����ǰ׷�����
            People_Input();  //����������
            system("cls");  //����
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //��ӡ���µ�����
            Game_State+=Game_Judge();  //��ñ�����Ӯ����Ϣ
            if(Game_State!=0) break;  //�����������˳�ѭ��
            color=-color;   //�ڰ׷��������壨һ��ֻ����һ�����ӣ�
        }
        White_Complain();  //�ڷ���������ʱ���׷�����Ͷ�ߺڷ�ʹ�ó�������
        Result_Output(Game_State);  //����������
    }
    //����Ϸѡ��Ϊ���˶�ս����ʱ��ģʽ����ʼ��ģʽ
    else if(Game_Option==3)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Player_Hint();  //��ʾĿǰ�Ǻڷ����ǰ׷�����
            People_Input_Time();  //����������
            system("cls");  //����
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //��ӡ���µ�����
            Game_State+=Game_Judge();    //��ñ�����Ӯ����Ϣ
            if(Game_State!=0) break;  //�����������˳�ѭ��
            color=-color;   //�ڰ׷��������壨ÿ��һ��ֻ����һ�����ӣ�
        }
        White_Complain();  //�ڷ���������ʱ���׷�����Ͷ�ߺڷ�ʹ�ó�������
        Result_Output(Game_State);  //����������
    }
    //����Ϸѡ��Ϊ�˻���ս����ʱ��ģʽ����ʼ��ģʽ
    else if(Game_Option==4)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Computer_Input();
            system("cls");  //����
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);//��ӡ���µ�����
            Game_State=+Game_Judge();    //��ñ�����Ӯ����Ϣ
            if(Game_State!=0) break;  //�����������˳�ѭ��
            color=-color;   //�ڰ׷��������壨һ��ֻ����һ�����ӣ�
            Player_Hint();  //��ʾĿǰ�Ǻڷ����ǰ׷�����
            People_Input_Time();  //���������壨��ʱ�汾��
            system("cls");  //����
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //��ӡ���µ�����
            Game_State+=Game_Judge();  //��ñ�����Ӯ����Ϣ
            if(Game_State!=0) break;  //�����������˳�ѭ��
            color=-color;   //�ڰ׷��������壨һ��ֻ����һ�����ӣ�
        }
        White_Complain();  //�ڷ���������ʱ���׷�����Ͷ�ߺڷ�ʹ�ó�������
        Result_Output(Game_State);  //����������
    }
    //�ۿ����Զ�ս
    else if(Game_Option==5)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Player_Hint();  //��ʾĿǰ�Ǻڷ����ǰ׷�����
            Sleep(1000);  //���Լ�������2.5�루���޸ģ�
            Computer_Input();  //����������
            system("cls");  //����
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //��ӡ���µ�����
            Game_State+=Game_Judge();    //��ñ�����Ӯ����Ϣ
            if(Game_State!=0) break;  //�����������˳�ѭ��
            color=-color;   //�ڰ׷��������壨ÿ��һ��ֻ����һ�����ӣ�
        }
        Result_Output(Game_State);  //����������
    }
}

int CJW_Game::Game_Judge()  //'0'Ϊδ��ʤ����'1'Ϊ�׷�ʤ��'2'Ϊ�ڷ�ʤ��'3'Ϊ����
{
    //�ж��Ƿ����
    int result=1;  //1����Ϊ���壬0�����Ǻ���
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++)
            if(Chess_Pieces[i][j]=='0') result=0;
    if(result) return 3;
    int n=0;  //������ͬ��ɫ������

    //�жϰ����Ƿ��ʤ
    for(int i=0; i<15; i++)  //�жϰ����ں�ķ���������������
    {
        n=0;
        for(int j=0; j<15; j++)
        {
            if(Chess_Pieces[i][j]=='1'||Chess_Pieces[i][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
    }
    for(int j=0; j<15; j++)  //�жϰ��������ķ���������������
    {
        n=0;
        for(int i=0; i<15; i++)
        {
            if(Chess_Pieces[i][j]=='1'||Chess_Pieces[i][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
    }
    for(int i=0; i<15; i++)  //�жϰ�����б�ķ���������������
    {
        n=0;
        for(int ii=i, j=0; j<15&&ii<15; ii++, j++)  //�жϰ�������ϵ����µ�б���������������ӣ����������Σ�
        {
            if(Chess_Pieces[ii][j]=='1'||Chess_Pieces[ii][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
        n=0;
        for(int ii=0, j=i; j<15&&ii<15; ii++, j++)  //�жϰ�������ϵ����µ�б���������������ӣ����������Σ�
        {
            if(Chess_Pieces[ii][j]=='1'||Chess_Pieces[ii][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
        n=0;
        for(int ii=i, j=0; j<15&&ii>-1; ii--, j++)  //�жϰ�������µ����ϵ�б���������������ӣ����������Σ�
        {
            if(Chess_Pieces[ii][j]=='1'||Chess_Pieces[ii][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
        for(int ii=14, j=i; j<15&&ii>-1; ii--, j++)  //�жϰ�������µ����ϵ�б���������������ӣ����������Σ�
        {
            if(Chess_Pieces[ii][j]=='1'||Chess_Pieces[ii][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
    }

    //�жϺ����Ƿ��ʤ
    for(int i=0; i<15; i++)  //�жϺ����ں�ķ���������������
    {
        n=0;
        for(int j=0; j<15; j++)
        {
            if(Chess_Pieces[i][j]=='2'||Chess_Pieces[i][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
    }
    for(int j=0; j<15; j++)  //�жϺ��������ķ���������������
    {
        n=0;
        for(int i=0; i<15; i++)
        {
            if(Chess_Pieces[i][j]=='2'||Chess_Pieces[i][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
    }
    for(int i=0; i<15; i++)  //�жϺ�����б�ķ���������������
    {
        n=0;
        for(int ii=i, j=0; j<15&&ii<15; ii++, j++)  //�жϺ�������ϵ����µ�б���������������ӣ����������Σ�
        {
            if(Chess_Pieces[ii][j]=='2'||Chess_Pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
        n=0;
        for(int ii=0, j=i; j<15&&ii<15; ii++, j++)  //�жϺ�������ϵ����µ�б���������������ӣ����������Σ�
        {
            if(Chess_Pieces[ii][j]=='2'||Chess_Pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
        n=0;
        for(int ii=i, j=0; j<15&&ii>-1; ii--, j++)  //�жϺ�������µ����ϵ�б���������������ӣ����������Σ�
        {
            if(Chess_Pieces[ii][j]=='2'||Chess_Pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
        for(int ii=14, j=i; j<15&&ii>-1; ii--, j++)  //�жϺ�������µ����ϵ�б���������������ӣ����������Σ�
        {
            if(Chess_Pieces[ii][j]=='2'||Chess_Pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
    }

    return 0;
}

void CJW_Game::White_Complain()  //�ڷ���������ʱ���׷�����Ͷ�ߺڷ�ʹ�ó�������
{
    if(Game_State==2)
    {
        cout << "   �����ӣ��Ƿ����ߡ�ʹ�ó������֣�(F�����ߣ�����������)" << '\r';
        char inp;
        inp=getch();
        if(inp=='f'||inp=='F')
        {
            CJW_Forbidden fbd;
            if(fbd.Forbidden2(Chess_Pieces)) Game_State=5;
            else
            {
                cout << "                     ��û��ʹ�ó������֣�                  " ;
            }
        }
    }
}

void CJW_Game::People_Input()
{
    int input;//�������
	while(1)  //ֱ���������һ����ȷ��������Ϣ
    {
		input=getch(); //�ȴ����̰���һ���ַ�
		if(input==27)  //�����ESC���˳�����
        {
			exit(0);
		}
		else if(input=='f'||input=='F')
        {
            CJW_Forbidden FBD;
            if(color==1)
            {
                if(FBD.Forbidden1(Chess_Pieces))
                {
                    Game_State=5;
                    break;
                }
                else cout << '\r' << "                       �ڷ�δʹ�ý��֣�";
            }
            else cout << '\a';  //�׷��޽���
        }
		else if(input==0x20) //����ǿո�
        {
            if(Chess_Pieces[Cursor_x][Cursor_y]=='0')  //����ô�û�����ӣ������������Ϣ
            {
                //����һ���ߵ����ӵ�״̬�������α��Բ
                for(int i=0; i<15; i++)
                {
                    for(int j=0; j<15; j++)
                    {
                        if(Chess_Pieces[i][j]=='1') Chess_Pieces[i][j]='3';
                        else if(Chess_Pieces[i][j]=='2') Chess_Pieces[i][j]='4';
                    }
                }
                //������µ����ӵ���Ϣ
                if(color==1) Chess_Pieces[Cursor_x][Cursor_y]='1';
                else Chess_Pieces[Cursor_x][Cursor_y]='2';
                break;
            }
            else cout <<'\a';  //��������������ʾ
		}
		else if(input==0xE0) //������µ��Ƿ������������������룬��һ��Ϊ0xE0��ʾ���µ��ǿ��Ƽ�
        {
            input=getch();   //��õڶ���������Ϣ
			switch(input)    //�жϷ���������ƶ����λ��
			{
				case 0x4B: Cursor_y--; break;
				case 0x48: Cursor_x--; break;
				case 0x4D: Cursor_y++; break;
				case 0x50: Cursor_x++; break;
			}
			if(Cursor_x<0)  Cursor_x=14; //������λ��Խ�����ƶ����Բ�
			if(Cursor_y<0)  Cursor_y=14;
			if(Cursor_x>14) Cursor_x=0;
			if(Cursor_y>14) Cursor_y=0;
			system("cls");  //����
			Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
			Player_Hint();  //��ʾĿǰ�Ǻڷ����ǰ׷�����
		}
		else cout <<'\a';  //��������������ʾ
	}
}

void CJW_Game::People_Input_Time()
{
    int input;//�������
    input_over=false;
    thread t1([&]()
    {
        while(1)  //ֱ���������һ����ȷ��������Ϣ
        {
            input=getch(); //�ȴ����̰���һ���ַ�
            if(input_over==true) return; //��������Ѿ�������ʱ�䵽�ˣ����������߳���ֹ
            if(input==27)  //�����ESC���˳�����
            {
                exit(0);
            }
            else if(input=='f'||input=='F')
            {
                CJW_Forbidden FBD;
                if(color==1)
                {
                    if(FBD.Forbidden1(Chess_Pieces))
                    {
                        Game_State=5;
                        input_over=true;
                        return;
                    }
                    else cout << '\r' << "                       �ڷ�δʹ�ý��֣�";
                }
                else cout << '\a';  //�׷��޽���
            }
            else if(input==0x20) //����ǿո�
            {
                if(Chess_Pieces[Cursor_x][Cursor_y]=='0')  //����ô�û�����ӣ������������Ϣ
                {
                    //����һ���ߵ����ӵ�״̬�������α��Բ
                    for(int i=0; i<15; i++)
                    {
                        for(int j=0; j<15; j++)
                        {
                            if(Chess_Pieces[i][j]=='1') Chess_Pieces[i][j]='3';
                            else if(Chess_Pieces[i][j]=='2') Chess_Pieces[i][j]='4';
                        }
                    }
                    //������µ����ӵ���Ϣ
                    if(color==1) Chess_Pieces[Cursor_x][Cursor_y]='1';
                    else Chess_Pieces[Cursor_x][Cursor_y]='2';
                    input_over=true;
                    return;
                }
                else cout <<'\a';  //��������������ʾ
            }
            else if(input==0xE0) //������µ��Ƿ������������������룬��һ��Ϊ0xE0��ʾ���µ��ǿ��Ƽ�
            {
                input=getch();   //��õڶ���������Ϣ
                switch(input)    //�жϷ���������ƶ����λ��
                {
                    case 0x4B: Cursor_y--; break;
                    case 0x48: Cursor_x--; break;
                    case 0x4D: Cursor_y++; break;
                    case 0x50: Cursor_x++; break;
                }
                if(Cursor_x<0)  Cursor_x=14; //������λ��Խ�����ƶ����Բ�
                if(Cursor_y<0)  Cursor_y=14;
                if(Cursor_x>14) Cursor_x=0;
                if(Cursor_y>14) Cursor_y=0;
                system("cls");  //����
                Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
                Player_Hint();  //��ʾĿǰ�Ǻڷ����ǰ׷�����
            }
            else cout <<'\a';  //��������������ʾ
        }
    });
    thread t2([&]()
    {
        int second=15;
        cout << "                 You have " << second << " seconds left.";
        while(second!=0)
        {
            for(int i=0; i<100; i++)  //��ʱ��
            {
                Sleep(10);
                if(input_over==true) goto cjw;  //��������Ѿ��������������߳���ֹ
            }
            second--;
            cout << '\r';
            if(second>9) cout << "                 You have " << second << " seconds left.";
            else          cout << "                  You have " << second << " seconds left.";
        }
        Game_State=4;
        input_over=true;
        cjw: return;
    });
    t1.detach();
    t2.detach();
    while(1)
    {
        Sleep(55);
        if(input_over==true) break;
    }
    Sleep(25);  //ȷ����ʱ�߳���ֹ
    return;
}

void CJW_Game::Computer_Input()
{
    CJW_AI Computer_Player;
    Computer_Player.getPosition(Chess_Pieces, color);  //�������壬�ж��������λ��
    //����һ���ߵ����ӵ�״̬�������α��Բ
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(Chess_Pieces[i][j]=='1') Chess_Pieces[i][j]='3';
            else if(Chess_Pieces[i][j]=='2') Chess_Pieces[i][j]='4';
        }
    }
    //������Ϣ�ж���AI������λ��
    if(color==1) Chess_Pieces[Computer_Player.AI_Piece_x][Computer_Player.AI_Piece_y]='1';
    else Chess_Pieces[Computer_Player.AI_Piece_x][Computer_Player.AI_Piece_y]='2';
    Cursor_x=Computer_Player.AI_Piece_x;
    Cursor_y=Computer_Player.AI_Piece_y;
}

void CJW_Game::Result_Output(int result)
{
    switch(result)
    {
        case 1:
            cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
            cout << "                   �������𷽻��ʤ��������            " << endl;
            cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
            cout << "                     ���������������                   " << endl;
            getch();
            break;
        case 2:
            cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
            cout << "                   �������񷽻��ʤ��������            " << endl;
            cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
            cout << "                     ���������������                   " << endl;
            getch();
            break;
        case 3:
            cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
            cout << "                   ������   ƽ��    ������               " << endl;
            cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
            cout << "                     ���������������                   " << endl;
            getch();
            break;
        case 4:
            if(color==1)
            {
                cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
                cout << "              �������𷽳�ʱ���񷽻��ʤ��������           " << endl;
                cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
                cout << "                     ���������������                   " << endl;
                getch();
            }
            else
            {
                cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
                cout << "              �������񷽳�ʱ���𷽻��ʤ��������           " << endl;
                cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
                cout << "                     ���������������                   " << endl;
                getch();
            }
            break;
        case 5:
            cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
            cout << "            ��������ʹ�ý��֣��𷽻��ʤ��������            " << endl;
            cout << "��  ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��" << endl;
            cout << "                     ���������������                   " << endl;
            getch();
            break;
    }
}

void CJW_Game::Player_Hint()
{
    if(color==1) cout << "                        �����֡�����" <<endl << "    1.��������ƶ���� 2.�ո������ 3.��F�����ߺڷ�ʹ�ý���" <<endl << "                   4.��ESC��ֱ���˳���Ϸ";
    else         cout << "                        �����֡�����" <<endl << "    1.��������ƶ���� 2.�ո������ 3.��ESC��ֱ���˳���Ϸ";
    cout << endl;
}
