#include "CJW_Forbidden.h"

CJW_Forbidden::CJW_Forbidden()
{
    //ctor
}

CJW_Forbidden::~CJW_Forbidden()
{
    //dtor
}

bool CJW_Forbidden::Live_Three(int line[9])  //判断某条线中有没有活三(五子棋术语)
{
    int black_number, white_number; //黑子数目和白子数目
    for(int i=0; i<4; i++)
    {
        black_number=0; white_number=0;  //每次循环初始化
        if(line[i]==0&&line[i+5]==0)     //根据五子棋中术语“活三”的定义
        {
            for(int j=1; j<=4; j++)
            {
                if(line[i+j]==1) black_number++;
                else if(line[i+j]==-1) white_number++;
            }
            if(black_number==3&&white_number==0)
                return true;
        }
    }
    return false;
}

bool CJW_Forbidden::Four(int line[9])  //判断某条线中有没有四(五子棋术语)
{
    int black_number, white_number; //黑子数目和白子数目
    for(int i=0; i<5; i++)
    {
        black_number=0; white_number=0;  //每次循环初始化
        for(int j=0; j<5; j++)
        {
            if(line[i+j]==1) black_number++;
            else if(line[i+j]==-1) white_number++;
        }
        if(black_number==4&&white_number==0)  //禁手规则中术语“四”的定义就是这样
            return true;
    }
    return false;
}

bool CJW_Forbidden::Forbidden1(char pieces[15][15])  //判断是否为三三禁手或四四禁手
{
    int Cx, Cy;  //用来存放黑方最新下的棋子的坐标；
    int LiveThree_Number=0, Four_Number=0;  //记录该处活三或四的数目
    int pieces_bigger[23][23]={-1};  //用来将输入的当前下棋的信息(pieces[15][15])转变为更大的数组，防止之后的运算中出现数组越界的情况。
    //为了使扩增的棋盘信息拥有原来棋盘的边界条件，将扩增的区域都设成是白子。(设定该处没有棋子为0，有黑子为1，有白子为-1）
    for(int i=0; i<15; i++)  //将输入的当前下棋的信息(pieces[15][15])转换到数组pieces_bigger中。
    {
        for(int j=0; j<15; j++)
        {
            if(pieces[i][j]=='0') pieces_bigger[i+4][j+4]=0;
            if(pieces[i][j]=='1'||pieces[i][j]=='3') pieces_bigger[i+4][j+4]=-1;
            if(pieces[i][j]=='2'||pieces[i][j]=='4') pieces_bigger[i+4][j+4]=1;
            if(pieces[i][j]=='2') { Cx=i+4; Cy=j+4; }
        }
    }
    //将黑方最新下的棋子周围的棋子信息读入到一维数组中（横，竖，斜线1，斜线2）
    int Horizontal_Line[9];  //横线上的棋子信息
    for(int i=-4; i<=4; i++) Horizontal_Line[i+4]=pieces_bigger[Cx][Cy+i];
    int Vertical_Line[9];  //竖线上的棋子信息
    for(int i=-4; i<=4; i++) Vertical_Line[i+4]=pieces_bigger[Cx+i][Cy];
    int Slash_Line1[9];  //斜线1上的棋子信息
    for(int i=-4; i<=4; i++) Slash_Line1[i+4]=pieces_bigger[Cx+i][Cy+i];
    int Slash_Line2[9];  //斜线2上的棋子信息
    for(int i=-4; i<=4; i++) Slash_Line2[i+4]=pieces_bigger[Cx-i][Cy+i];
    //判断横线方向上是否存在活三或四
    if(Live_Three(Horizontal_Line))
    {
        if(Four(Horizontal_Line)) Four_Number++;
        else LiveThree_Number++;
    }
    else if(Four(Horizontal_Line))
        Four_Number++;
    //判断竖线方向上是否存在活三或四
    if(Live_Three(Vertical_Line))
    {
        if(Four(Vertical_Line)) Four_Number++;
        else LiveThree_Number++;
    }
    else if(Four(Vertical_Line))
        Four_Number++;
    //判断斜线1方向上是否存在活三或四
    if(Live_Three(Slash_Line1))
    {
        if(Four(Slash_Line1)) Four_Number++;
        else LiveThree_Number++;
    }
    else if(Four(Slash_Line1))
        Four_Number++;
    //判断斜线2方向上是否存在活三或四
    if(Live_Three(Slash_Line2))
    {
        if(Four(Slash_Line2)) Four_Number++;
        else LiveThree_Number++;
    }
    else if(Four(Slash_Line2))
        Four_Number++;
    //根据计算的活三和四的数量，返回相应结果
    if(LiveThree_Number>1) return true;
    if(Four_Number>1) return true;
    return false;
}

bool CJW_Forbidden::Forbidden2(char pieces[15][15])  //判断是否为长连禁手
{
    int n=0;  //连续的黑子数目
    for(int i=0; i<15; i++)  //判断黑棋在横的方向有无长连
    {
        n=0;
        for(int j=0; j<15; j++)
        {
            if(pieces[i][j]=='2'||pieces[i][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
    }
    for(int j=0; j<15; j++)  //判断黑棋在竖的方向有无长连
    {
        n=0;
        for(int i=0; i<15; i++)
        {
            if(pieces[i][j]=='2'||pieces[i][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
    }
    for(int i=0; i<15; i++)  //判断黑棋在斜的方向有无长连
    {
        n=0;
        for(int ii=i, j=0; j<15&&ii<15; ii++, j++)  //判断黑棋从左上到右下的斜方向有无长连（左下三角形）
        {
            if(pieces[ii][j]=='2'||pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
        n=0;
        for(int ii=0, j=i; j<15&&ii<15; ii++, j++)  //判断黑棋从左上到右下的斜方向有无长连（右上三角形）
        {
            if(pieces[ii][j]=='2'||pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
        n=0;
        for(int ii=i, j=0; j<15&&ii>-1; ii--, j++)  //判断黑棋从左下到右上的斜方向有无长连（左上三角形）
        {
            if(pieces[ii][j]=='2'||pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
        for(int ii=14, j=i; j<15&&ii>-1; ii--, j++)  //判断黑棋从左下到右上的斜方向有无长连（右下三角形）
        {
            if(pieces[ii][j]=='2'||pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
    }
    return false;
}
