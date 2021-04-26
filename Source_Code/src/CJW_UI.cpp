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
    system("title 五子棋游戏 By CJW ");  //设置标题
	system("mode con cols=54 lines=20");  //设置窗口大小
	system("color E0");  //设置颜色
	system("cls");  //清屏
	cout<<endl<<endl;
	cout<<" ○●○●○●○●○●○●○●○●○●○●○●○●○●"<<endl;
	cout<<" ●○●○●○●○●○●○●○●○●○●○●○●○●○"<<endl;
	cout<<" ○●                                            ○●"<<endl;
	cout<<" ●○                                            ●○"<<endl;
	cout<<" ○●        欢       迎       使       用       ○●"<<endl;
	cout<<" ●○                                            ●○"<<endl;
	cout<<" ○●              五      子     棋             ○●"<<endl;
	cout<<" ●○                                            ●○"<<endl;
	cout<<" ○●                                            ○●"<<endl;
	cout<<" ●○                                            ●○"<<endl;
	cout<<" ○●   设计者 陈俊武(CJW)     指导老师 杨力祥   ○●"<<endl;
	cout<<" ●○                                            ●○"<<endl;
	cout<<" ○●                 C++程序设计                ○●"<<endl;
	cout<<" ●○                                            ●○"<<endl;
	cout<<" ○●               中国科学院大学              ○●"<<endl;
	cout<<" ●○●○●○●○●○●○●○●○●○●○●○●○●○"<<endl;
	cout<<" ○●○●○●○●○●○●○●○●○●○●○●○●○●"<<endl;
	cout<<"                     按任意键继续"<<endl;
    getch();
}

int CJW_UI::GameOption_Interface()
{
    system("mode con cols=54 lines=20");  //设置窗口大小
    int input;  //输入变量
    int option=1;
	while(1)  //直到玩家输入一次正确的信息
    {
        system("cls");  //清屏
        switch(option)  //输出所有游戏模式的选项
        {
            case 1:
                cout << endl ;
                cout << "                游     戏     模     式" << endl << endl << endl;
                cout << "             ○○○人人对战(不计时)●●●" << endl << endl << endl;
                cout << "                   人机对战(不计时)   " << endl << endl << endl;
                cout << "                    人人对战(计时)   " << endl << endl << endl;
                cout << "                    人机对战(计时)   " << endl << endl << endl;
                cout << "                     观看电脑对战   " << endl << endl << endl;
                cout << " 1.按上下方向键移动 2.按空格键确定 3.按EXC键直接退出";
                break;
            case 2:
                cout << endl ;
                cout << "                游     戏     模     式" << endl << endl << endl;
                cout << "                   人人对战(不计时)   " << endl << endl << endl;
                cout << "             ○○○人机对战(不计时)●●●" << endl << endl << endl;
                cout << "                    人人对战(计时)   " << endl << endl << endl;
                cout << "                    人机对战(计时)   " << endl << endl << endl;
                cout << "                     观看电脑对战   " << endl << endl << endl;
                cout << " 1.按上下方向键移动 2.按空格键确定 3.按EXC键直接退出";
                break;
            case 3:
                cout << endl ;
                cout << "                游     戏     模     式" << endl << endl << endl;
                cout << "                   人人对战(不计时)   " << endl << endl << endl;
                cout << "                   人机对战(不计时)   " << endl << endl << endl;
                cout << "              ○○○人人对战(计时)●●●" << endl << endl << endl;
                cout << "                    人机对战(计时)   " << endl << endl << endl;
                cout << "                     观看电脑对战   " << endl << endl << endl;
                cout << " 1.按上下方向键移动 2.按空格键确定 3.按EXC键直接退出";
                break;
            case 4:
                cout << endl ;
                cout << "                游     戏     模     式" << endl << endl << endl;
                cout << "                   人人对战(不计时)   " << endl << endl << endl;
                cout << "                   人机对战(不计时)   " << endl << endl << endl;
                cout << "                    人人对战(计时)   " << endl << endl << endl;
                cout << "              ○○○人机对战(计时)●●●" << endl << endl << endl;
                cout << "                     观看电脑对战   " << endl << endl << endl;
                cout << " 1.按上下方向键移动 2.按空格键确定 3.按EXC键直接退出";
                break;
            case 5:
                cout << endl ;
                cout << "                游     戏     模     式" << endl << endl << endl;
                cout << "                   人人对战(不计时)   " << endl << endl << endl;
                cout << "                   人机对战(不计时)   " << endl << endl << endl;
                cout << "                    人人对战(计时)   " << endl << endl << endl;
                cout << "                    人机对战(计时)   " << endl << endl << endl;
                cout << "               ○○○观看电脑对战●●●" << endl << endl << endl;
                cout << " 1.按上下方向键移动 2.按空格键确定 3.按EXC键直接退出";
                break;
        }
		input=getch(); //等待键盘按下一个字符
		if(input==27)  //如果是ESC则退出程序
        {
			exit(0);
		}
		else if(input==0x20) //如果是空格
            return option;
		else if(input==0xE0) //如果按下的是方向键，会填充两次输入，第一次为0xE0表示按下的是控制键
        {
            input=getch();   //获得第二次输入信息
			switch(input)    //判断方向键方向并移动光标位置
			{
				case 0x48:
                    option--; break;
				case 0x50:
				    option++;
			}
			if(option<1)  option=5; //如果光标位置越界则移动到对侧
			if(option>5) option=1;
		}
		else cout <<'\a';  //按键错误，响铃提示
	}
}

int CJW_UI::GameOver_Interface()
{
    system("mode con cols=54 lines=20");  //设置窗口大小
    int input;  //输入变量
    int option=1;
	while(1)  //直到玩家输入一次正确的信息
    {
        system("cls");  //清屏
        switch(option)  //输出所有游戏结束后的选项
        {
            case 1:
                cout << endl << endl;
                cout << "               游     戏     结     束 ！" << endl << endl ;
                cout << "                  您      选      择" << endl << endl << endl;
                cout << "                ○○○返回主菜单●●●   " << endl << endl << endl<< endl;
                cout << "                       重新游戏   " << endl << endl << endl << endl;
                cout << "                       退出游戏   " << endl << endl << endl << endl;
                cout << " 1.按上下方向键移动 2.按空格键确定 3.按EXC键直接退出" ;
                break;
            case 2:
                cout << endl << endl;
                cout << "               游     戏     结     束 ！" << endl << endl ;
                cout << "                  您      选      择" << endl << endl << endl;
                cout << "                      返回主菜单      " << endl << endl << endl<< endl;
                cout << "                 ○○○重新游戏●●●   " << endl << endl << endl << endl;
                cout << "                       退出游戏   " << endl << endl << endl << endl;
                cout << " 1.按上下方向键移动 2.按空格键确定 3.按EXC键直接退出" ;
                break;
            case 3:
                cout << endl << endl;
                cout << "               游     戏     结     束 ！" << endl << endl ;
                cout << "                  您      选      择" << endl << endl << endl;
                cout << "                      返回主菜单      " << endl << endl << endl<< endl;
                cout << "                       重新游戏   " << endl << endl << endl << endl;
                cout << "                 ○○○退出游戏●●●   " << endl << endl << endl << endl;
                cout << " 1.按上下方向键移动 2.按空格键确定 3.按EXC键直接退出" ;
                break;
        }
		input=getch(); //等待键盘按下一个字符
		if(input==27)  //如果是ESC则退出程序
        {
			exit(0);
		}
		else if(input==0x20) //如果是空格
            return option;
		else if(input==0xE0) //如果按下的是方向键，会填充两次输入，第一次为0xE0表示按下的是控制键
        {
            input=getch();   //获得第二次输入信息
			switch(input)    //判断方向键方向并移动光标位置
			{
				case 0x48:
                    option--; break;
				case 0x50:
				    option++; break;
			}
			if(option<1)  option=3; //如果光标位置越界则移动到对侧
			if(option>3)  option=1;
		}
		else cout <<'\a';  //按键错误，响铃提示
	}
}

void CJW_UI::Exit_Interface()
{
    system("mode con cols=54 lines=20");  //设置窗口大小
    system("cls");  //清屏
    cout << endl << endl<< endl << endl << endl<< endl << endl << endl;
    cout << "          感    谢    您    的    使    用 ！" << endl << endl ;
    cout << "                 Thank you for using!";
    cout << endl << endl << endl<< endl << endl << endl << endl << endl;
    Sleep(1500);
}
