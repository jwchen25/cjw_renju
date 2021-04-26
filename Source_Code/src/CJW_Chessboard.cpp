#include "CJW_Chessboard.h"


CJW_Chessboard::CJW_Chessboard()
{
    Chessboard_size = 15; //默认是五子棋的棋盘(大小为15)，如果想改变棋盘大小，请使用成员函数Rewrite_SizeofBoard。
}

CJW_Chessboard::~CJW_Chessboard()
{
    //dtor
}

void CJW_Chessboard::Rewrite_SizeofBoard(int n)
{
    Chessboard_size = n;
}

void CJW_Chessboard::Board_print(char chess[15][15], int Cx, int Cy)
{
    char Board[Chessboard_size*2+1][Chessboard_size*2+1];
    for(int i=0; i<Chessboard_size*2+1; i++) //初始化数组Board
        for(int j=0; j<Chessboard_size*2+1; j++) Board[i][j]='0';

    //接下去初始化没有棋子的棋盘；其中：
    for(int i=0; i<Chessboard_size; i++)
        for(int j=1; j<Chessboard_size; j++)   Board[i*2+1][j*2]='b';
    for(int i=1; i<Chessboard_size; i++)
        for(int j=0; j<Chessboard_size; j++)   Board[i*2][j*2+1]='e';
    for(int i=1; i<Chessboard_size; i++)
        for(int j=1; j<Chessboard_size; j++)   Board[i*2][j*2]='l';
    for(int i=1; i<Chessboard_size-1; i++)
        for(int j=1; j<Chessboard_size-1; j++) Board[i*2+1][j*2+1]='g';
    for(int i=1; i<Chessboard_size-1; i++)     Board[1][i*2+1]='c';
    for(int i=1; i<Chessboard_size-1; i++)     Board[Chessboard_size*2-1][i*2+1]='j';
    for(int i=1; i<Chessboard_size-1; i++)     Board[i*2+1][1]='f';
    for(int i=1; i<Chessboard_size-1; i++)     Board[i*2+1][Chessboard_size*2-1]='h';
    Board[1][1]='a';
    Board[1][Chessboard_size*2-1]='d';
    Board[Chessboard_size*2-1][1]='i';
    Board[Chessboard_size*2-1][Chessboard_size*2-1]='k';

    //读入棋子的信息
    for(int i=0; i<Chessboard_size; i++)
    {
        for(int j=0; j<Chessboard_size; j++)
        {
            switch(chess[i][j])
            {
                case '1': Board[i*2+1][j*2+1]='1'; break;
                case '2': Board[i*2+1][j*2+1]='2'; break;
                case '3': Board[i*2+1][j*2+1]='3'; break;
                case '4': Board[i*2+1][j*2+1]='4'; break;
                default: break;
            }
        }
    }

    //读入光标信息
    Board[Cx*2][Cy*2]='a';
    Board[Cx*2][Cy*2+2]='d';
    Board[Cx*2+2][Cy*2]='i';
    Board[Cx*2+2][Cy*2+2]='k';

    //输出棋盘、棋子和光标
    for(int i=0; i<Chessboard_size*2+1; i++)
    {
        for(int j=0; j<Chessboard_size*2+1; j++)
        {
            switch(Board[i][j])
            {
                case 'a': cout << "┌ "; break;
                case 'b': cout << "━ "; break;
                case 'c': cout << "┬ "; break;
                case 'd': cout << "┐ "; break;
                case 'e': cout << "┃ "; break;
                case 'f': cout << "├ "; break;
                case 'g': cout << "┼ "; break;
                case 'h': cout << "┤ "; break;
                case 'i': cout << "└ "; break;
                case 'j': cout << "┴ "; break;
                case 'k': cout << "┘ "; break;
                case 'l': cout << "  "; break;
                case '1': cout << "△"; break;
                case '2': cout << "▲"; break;
                case '3': cout << "○"; break;
                case '4': cout << "●"; break;
                default : cout << "  "; break;
            }
        }
        cout << endl << flush;
    }
}
