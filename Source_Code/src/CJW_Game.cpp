#include "CJW_Game.h"


CJW_Game::CJW_Game()
{
    Game_Option=1; //默认游戏选项为人人对战
    Game_State=0;  //输赢未分，正在下棋
    Cursor_x=7;  //光标在中心位置
    Cursor_y=7;
    color=-1;  //1为白棋，-1为黑棋，默认黑方先下
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++) Chess_Pieces[i][j]='0';
}

CJW_Game::~CJW_Game()
{
    //dtor
}

void CJW_Game::Game_Start()
{
    color=-1;  //默认黑方先下
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++) Chess_Pieces[i][j]='0';
    Game_State=0;  //输赢未分，正在下棋
    Cursor_x=7;  //光标在中心位置
    Cursor_y=7;
}

void CJW_Game::Game_Running()
{
    system("mode con cols=62 lines=35");  //设置窗口大小
    //若游戏选项为人人对战(不计时)，开始人人对战(不计时)
    if(Game_Option==1)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Player_Hint();  //提示目前是黑方还是白方下棋
            People_Input();  //人棋手下棋
            system("cls");  //清屏
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //打印最新的棋盘
            Game_State+=Game_Judge();    //获得比赛输赢等信息
            if(Game_State!=0) break;  //比赛结束，退出循环
            color=-color;   //黑白方轮流下棋（每人一次只能下一个棋子）
        }
        White_Complain();  //黑方连成五子时，白方可以投诉黑方使用长连禁手
        Result_Output(Game_State);  //输出比赛结果
    }
    //若游戏选项为人机对战(不计时)，开始人机对战(不计时)
    else if(Game_Option==2)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Computer_Input();
            system("cls");  //清屏
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);//打印最新的棋盘
            Game_State=+Game_Judge();    //获得比赛输赢等信息
            if(Game_State!=0) break;  //比赛结束，退出循环
            color=-color;   //黑白方轮流下棋（一次只能下一个棋子）
            Player_Hint();  //提示目前是黑方还是白方下棋
            People_Input();  //人棋手下棋
            system("cls");  //清屏
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //打印最新的棋盘
            Game_State+=Game_Judge();  //获得比赛输赢等信息
            if(Game_State!=0) break;  //比赛结束，退出循环
            color=-color;   //黑白方轮流下棋（一次只能下一个棋子）
        }
        White_Complain();  //黑方连成五子时，白方可以投诉黑方使用长连禁手
        Result_Output(Game_State);  //输出比赛结果
    }
    //若游戏选项为人人对战（计时）模式，开始该模式
    else if(Game_Option==3)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Player_Hint();  //提示目前是黑方还是白方下棋
            People_Input_Time();  //人棋手下棋
            system("cls");  //清屏
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //打印最新的棋盘
            Game_State+=Game_Judge();    //获得比赛输赢等信息
            if(Game_State!=0) break;  //比赛结束，退出循环
            color=-color;   //黑白方轮流下棋（每人一次只能下一个棋子）
        }
        White_Complain();  //黑方连成五子时，白方可以投诉黑方使用长连禁手
        Result_Output(Game_State);  //输出比赛结果
    }
    //若游戏选项为人机对战（计时）模式，开始该模式
    else if(Game_Option==4)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Computer_Input();
            system("cls");  //清屏
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);//打印最新的棋盘
            Game_State=+Game_Judge();    //获得比赛输赢等信息
            if(Game_State!=0) break;  //比赛结束，退出循环
            color=-color;   //黑白方轮流下棋（一次只能下一个棋子）
            Player_Hint();  //提示目前是黑方还是白方下棋
            People_Input_Time();  //人棋手下棋（计时版本）
            system("cls");  //清屏
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //打印最新的棋盘
            Game_State+=Game_Judge();  //获得比赛输赢等信息
            if(Game_State!=0) break;  //比赛结束，退出循环
            color=-color;   //黑白方轮流下棋（一次只能下一个棋子）
        }
        White_Complain();  //黑方连成五子时，白方可以投诉黑方使用长连禁手
        Result_Output(Game_State);  //输出比赛结果
    }
    //观看电脑对战
    else if(Game_Option==5)
    {
        Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
        while(1)
        {
            Player_Hint();  //提示目前是黑方还是白方下棋
            Sleep(1000);  //电脑间下棋间隔2.5秒（可修改）
            Computer_Input();  //人棋手下棋
            system("cls");  //清屏
            Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);  //打印最新的棋盘
            Game_State+=Game_Judge();    //获得比赛输赢等信息
            if(Game_State!=0) break;  //比赛结束，退出循环
            color=-color;   //黑白方轮流下棋（每人一次只能下一个棋子）
        }
        Result_Output(Game_State);  //输出比赛结果
    }
}

int CJW_Game::Game_Judge()  //'0'为未分胜负；'1'为白方胜；'2'为黑方胜；'3'为和棋
{
    //判断是否和棋
    int result=1;  //1代表为和棋，0代表不是和棋
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++)
            if(Chess_Pieces[i][j]=='0') result=0;
    if(result) return 3;
    int n=0;  //连续的同颜色棋子数

    //判断白棋是否获胜
    for(int i=0; i<15; i++)  //判断白棋在横的方向有无连成五子
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
    for(int j=0; j<15; j++)  //判断白棋在竖的方向有无连成五子
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
    for(int i=0; i<15; i++)  //判断白棋在斜的方向有无连成五子
    {
        n=0;
        for(int ii=i, j=0; j<15&&ii<15; ii++, j++)  //判断白棋从左上到右下的斜方向有无连成五子（左下三角形）
        {
            if(Chess_Pieces[ii][j]=='1'||Chess_Pieces[ii][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
        n=0;
        for(int ii=0, j=i; j<15&&ii<15; ii++, j++)  //判断白棋从左上到右下的斜方向有无连成五子（右上三角形）
        {
            if(Chess_Pieces[ii][j]=='1'||Chess_Pieces[ii][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
        n=0;
        for(int ii=i, j=0; j<15&&ii>-1; ii--, j++)  //判断白棋从左下到右上的斜方向有无连成五子（左上三角形）
        {
            if(Chess_Pieces[ii][j]=='1'||Chess_Pieces[ii][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
        for(int ii=14, j=i; j<15&&ii>-1; ii--, j++)  //判断白棋从左下到右上的斜方向有无连成五子（右下三角形）
        {
            if(Chess_Pieces[ii][j]=='1'||Chess_Pieces[ii][j]=='3')
                n++;
            else n=0;
            if(n==5) return 1;
        }
    }

    //判断黑棋是否获胜
    for(int i=0; i<15; i++)  //判断黑棋在横的方向有无连成五子
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
    for(int j=0; j<15; j++)  //判断黑棋在竖的方向有无连成五子
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
    for(int i=0; i<15; i++)  //判断黑棋在斜的方向有无连成五子
    {
        n=0;
        for(int ii=i, j=0; j<15&&ii<15; ii++, j++)  //判断黑棋从左上到右下的斜方向有无连成五子（左下三角形）
        {
            if(Chess_Pieces[ii][j]=='2'||Chess_Pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
        n=0;
        for(int ii=0, j=i; j<15&&ii<15; ii++, j++)  //判断黑棋从左上到右下的斜方向有无连成五子（右上三角形）
        {
            if(Chess_Pieces[ii][j]=='2'||Chess_Pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
        n=0;
        for(int ii=i, j=0; j<15&&ii>-1; ii--, j++)  //判断黑棋从左下到右上的斜方向有无连成五子（左上三角形）
        {
            if(Chess_Pieces[ii][j]=='2'||Chess_Pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
        for(int ii=14, j=i; j<15&&ii>-1; ii--, j++)  //判断黑棋从左下到右上的斜方向有无连成五子（右下三角形）
        {
            if(Chess_Pieces[ii][j]=='2'||Chess_Pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n==5) return 2;
        }
    }

    return 0;
}

void CJW_Game::White_Complain()  //黑方连成五子时，白方可以投诉黑方使用长连禁手
{
    if(Game_State==2)
    {
        cout << "   ●方五子，是否申诉●方使用长连禁手？(F键申诉，其它键认输)" << '\r';
        char inp;
        inp=getch();
        if(inp=='f'||inp=='F')
        {
            CJW_Forbidden fbd;
            if(fbd.Forbidden2(Chess_Pieces)) Game_State=5;
            else
            {
                cout << "                     ●方没有使用长连禁手！                  " ;
            }
        }
    }
}

void CJW_Game::People_Input()
{
    int input;//输入变量
	while(1)  //直到玩家输入一次正确的下棋信息
    {
		input=getch(); //等待键盘按下一个字符
		if(input==27)  //如果是ESC则退出程序
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
                else cout << '\r' << "                       黑方未使用禁手！";
            }
            else cout << '\a';  //白方无禁手
        }
		else if(input==0x20) //如果是空格
        {
            if(Chess_Pieces[Cursor_x][Cursor_y]=='0')  //如果该处没有棋子，则读入下棋信息
            {
                //将上一步走的棋子的状态从三角形变成圆
                for(int i=0; i<15; i++)
                {
                    for(int j=0; j<15; j++)
                    {
                        if(Chess_Pieces[i][j]=='1') Chess_Pieces[i][j]='3';
                        else if(Chess_Pieces[i][j]=='2') Chess_Pieces[i][j]='4';
                    }
                }
                //读入刚下的棋子的信息
                if(color==1) Chess_Pieces[Cursor_x][Cursor_y]='1';
                else Chess_Pieces[Cursor_x][Cursor_y]='2';
                break;
            }
            else cout <<'\a';  //按键错误，响铃提示
		}
		else if(input==0xE0) //如果按下的是方向键，会填充两次输入，第一次为0xE0表示按下的是控制键
        {
            input=getch();   //获得第二次输入信息
			switch(input)    //判断方向键方向并移动光标位置
			{
				case 0x4B: Cursor_y--; break;
				case 0x48: Cursor_x--; break;
				case 0x4D: Cursor_y++; break;
				case 0x50: Cursor_x++; break;
			}
			if(Cursor_x<0)  Cursor_x=14; //如果光标位置越界则移动到对侧
			if(Cursor_y<0)  Cursor_y=14;
			if(Cursor_x>14) Cursor_x=0;
			if(Cursor_y>14) Cursor_y=0;
			system("cls");  //清屏
			Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
			Player_Hint();  //提示目前是黑方还是白方下棋
		}
		else cout <<'\a';  //按键错误，响铃提示
	}
}

void CJW_Game::People_Input_Time()
{
    int input;//输入变量
    input_over=false;
    thread t1([&]()
    {
        while(1)  //直到玩家输入一次正确的下棋信息
        {
            input=getch(); //等待键盘按下一个字符
            if(input_over==true) return; //如果输入已经结束（时间到了），该输入线程终止
            if(input==27)  //如果是ESC则退出程序
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
                    else cout << '\r' << "                       黑方未使用禁手！";
                }
                else cout << '\a';  //白方无禁手
            }
            else if(input==0x20) //如果是空格
            {
                if(Chess_Pieces[Cursor_x][Cursor_y]=='0')  //如果该处没有棋子，则读入下棋信息
                {
                    //将上一步走的棋子的状态从三角形变成圆
                    for(int i=0; i<15; i++)
                    {
                        for(int j=0; j<15; j++)
                        {
                            if(Chess_Pieces[i][j]=='1') Chess_Pieces[i][j]='3';
                            else if(Chess_Pieces[i][j]=='2') Chess_Pieces[i][j]='4';
                        }
                    }
                    //读入刚下的棋子的信息
                    if(color==1) Chess_Pieces[Cursor_x][Cursor_y]='1';
                    else Chess_Pieces[Cursor_x][Cursor_y]='2';
                    input_over=true;
                    return;
                }
                else cout <<'\a';  //按键错误，响铃提示
            }
            else if(input==0xE0) //如果按下的是方向键，会填充两次输入，第一次为0xE0表示按下的是控制键
            {
                input=getch();   //获得第二次输入信息
                switch(input)    //判断方向键方向并移动光标位置
                {
                    case 0x4B: Cursor_y--; break;
                    case 0x48: Cursor_x--; break;
                    case 0x4D: Cursor_y++; break;
                    case 0x50: Cursor_x++; break;
                }
                if(Cursor_x<0)  Cursor_x=14; //如果光标位置越界则移动到对侧
                if(Cursor_y<0)  Cursor_y=14;
                if(Cursor_x>14) Cursor_x=0;
                if(Cursor_y>14) Cursor_y=0;
                system("cls");  //清屏
                Game_Board.Board_print(Chess_Pieces, Cursor_x, Cursor_y);
                Player_Hint();  //提示目前是黑方还是白方下棋
            }
            else cout <<'\a';  //按键错误，响铃提示
        }
    });
    thread t2([&]()
    {
        int second=15;
        cout << "                 You have " << second << " seconds left.";
        while(second!=0)
        {
            for(int i=0; i<100; i++)  //计时用
            {
                Sleep(10);
                if(input_over==true) goto cjw;  //如果输入已经结束，该输入线程终止
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
    Sleep(25);  //确保计时线程终止
    return;
}

void CJW_Game::Computer_Input()
{
    CJW_AI Computer_Player;
    Computer_Player.getPosition(Chess_Pieces, color);  //电脑下棋，判断最佳下棋位置
    //将上一步走的棋子的状态从三角形变成圆
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(Chess_Pieces[i][j]=='1') Chess_Pieces[i][j]='3';
            else if(Chess_Pieces[i][j]=='2') Chess_Pieces[i][j]='4';
        }
    }
    //棋盘信息中读入AI的下棋位置
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
            cout << "○  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ○" << endl;
            cout << "                   ！！！○方获得胜利！！！            " << endl;
            cout << "○  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ○" << endl;
            cout << "                     （按任意键继续）                   " << endl;
            getch();
            break;
        case 2:
            cout << "●  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ●" << endl;
            cout << "                   ！！！●方获得胜利！！！            " << endl;
            cout << "●  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ●" << endl;
            cout << "                     （按任意键继续）                   " << endl;
            getch();
            break;
        case 3:
            cout << "○  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ●" << endl;
            cout << "                   ！！！   平局    ！！！               " << endl;
            cout << "●  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ○" << endl;
            cout << "                     （按任意键继续）                   " << endl;
            getch();
            break;
        case 4:
            if(color==1)
            {
                cout << "○  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ●" << endl;
                cout << "              ！！！○方超时，●方获得胜利！！！           " << endl;
                cout << "●  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ○" << endl;
                cout << "                     （按任意键继续）                   " << endl;
                getch();
            }
            else
            {
                cout << "○  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ●" << endl;
                cout << "              ！！！●方超时，○方获得胜利！！！           " << endl;
                cout << "●  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ○" << endl;
                cout << "                     （按任意键继续）                   " << endl;
                getch();
            }
            break;
        case 5:
            cout << "○  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ○" << endl;
            cout << "            ！！！●方使用禁手，○方获得胜利！！！            " << endl;
            cout << "○  ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ━   ○" << endl;
            cout << "                     （按任意键继续）                   " << endl;
            getch();
            break;
    }
}

void CJW_Game::Player_Hint()
{
    if(color==1) cout << "                        请棋手○下棋" <<endl << "    1.按方向键移动光标 2.空格键下棋 3.按F键申诉黑方使用禁手" <<endl << "                   4.按ESC键直接退出游戏";
    else         cout << "                        请棋手●下棋" <<endl << "    1.按方向键移动光标 2.空格键下棋 3.按ESC键直接退出游戏";
    cout << endl;
}
