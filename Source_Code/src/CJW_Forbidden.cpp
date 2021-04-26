#include "CJW_Forbidden.h"

CJW_Forbidden::CJW_Forbidden()
{
    //ctor
}

CJW_Forbidden::~CJW_Forbidden()
{
    //dtor
}

bool CJW_Forbidden::Live_Three(int line[9])  //�ж�ĳ��������û�л���(����������)
{
    int black_number, white_number; //������Ŀ�Ͱ�����Ŀ
    for(int i=0; i<4; i++)
    {
        black_number=0; white_number=0;  //ÿ��ѭ����ʼ��
        if(line[i]==0&&line[i+5]==0)     //����������������������Ķ���
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

bool CJW_Forbidden::Four(int line[9])  //�ж�ĳ��������û����(����������)
{
    int black_number, white_number; //������Ŀ�Ͱ�����Ŀ
    for(int i=0; i<5; i++)
    {
        black_number=0; white_number=0;  //ÿ��ѭ����ʼ��
        for(int j=0; j<5; j++)
        {
            if(line[i+j]==1) black_number++;
            else if(line[i+j]==-1) white_number++;
        }
        if(black_number==4&&white_number==0)  //���ֹ���������ġ��Ķ����������
            return true;
    }
    return false;
}

bool CJW_Forbidden::Forbidden1(char pieces[15][15])  //�ж��Ƿ�Ϊ�������ֻ����Ľ���
{
    int Cx, Cy;  //������źڷ������µ����ӵ����ꣻ
    int LiveThree_Number=0, Four_Number=0;  //��¼�ô��������ĵ���Ŀ
    int pieces_bigger[23][23]={-1};  //����������ĵ�ǰ�������Ϣ(pieces[15][15])ת��Ϊ��������飬��ֹ֮��������г�������Խ��������
    //Ϊ��ʹ������������Ϣӵ��ԭ�����̵ı߽�����������������������ǰ��ӡ�(�趨�ô�û������Ϊ0���к���Ϊ1���а���Ϊ-1��
    for(int i=0; i<15; i++)  //������ĵ�ǰ�������Ϣ(pieces[15][15])ת��������pieces_bigger�С�
    {
        for(int j=0; j<15; j++)
        {
            if(pieces[i][j]=='0') pieces_bigger[i+4][j+4]=0;
            if(pieces[i][j]=='1'||pieces[i][j]=='3') pieces_bigger[i+4][j+4]=-1;
            if(pieces[i][j]=='2'||pieces[i][j]=='4') pieces_bigger[i+4][j+4]=1;
            if(pieces[i][j]=='2') { Cx=i+4; Cy=j+4; }
        }
    }
    //���ڷ������µ�������Χ��������Ϣ���뵽һά�����У��ᣬ����б��1��б��2��
    int Horizontal_Line[9];  //�����ϵ�������Ϣ
    for(int i=-4; i<=4; i++) Horizontal_Line[i+4]=pieces_bigger[Cx][Cy+i];
    int Vertical_Line[9];  //�����ϵ�������Ϣ
    for(int i=-4; i<=4; i++) Vertical_Line[i+4]=pieces_bigger[Cx+i][Cy];
    int Slash_Line1[9];  //б��1�ϵ�������Ϣ
    for(int i=-4; i<=4; i++) Slash_Line1[i+4]=pieces_bigger[Cx+i][Cy+i];
    int Slash_Line2[9];  //б��2�ϵ�������Ϣ
    for(int i=-4; i<=4; i++) Slash_Line2[i+4]=pieces_bigger[Cx-i][Cy+i];
    //�жϺ��߷������Ƿ���ڻ�������
    if(Live_Three(Horizontal_Line))
    {
        if(Four(Horizontal_Line)) Four_Number++;
        else LiveThree_Number++;
    }
    else if(Four(Horizontal_Line))
        Four_Number++;
    //�ж����߷������Ƿ���ڻ�������
    if(Live_Three(Vertical_Line))
    {
        if(Four(Vertical_Line)) Four_Number++;
        else LiveThree_Number++;
    }
    else if(Four(Vertical_Line))
        Four_Number++;
    //�ж�б��1�������Ƿ���ڻ�������
    if(Live_Three(Slash_Line1))
    {
        if(Four(Slash_Line1)) Four_Number++;
        else LiveThree_Number++;
    }
    else if(Four(Slash_Line1))
        Four_Number++;
    //�ж�б��2�������Ƿ���ڻ�������
    if(Live_Three(Slash_Line2))
    {
        if(Four(Slash_Line2)) Four_Number++;
        else LiveThree_Number++;
    }
    else if(Four(Slash_Line2))
        Four_Number++;
    //���ݼ���Ļ������ĵ�������������Ӧ���
    if(LiveThree_Number>1) return true;
    if(Four_Number>1) return true;
    return false;
}

bool CJW_Forbidden::Forbidden2(char pieces[15][15])  //�ж��Ƿ�Ϊ��������
{
    int n=0;  //�����ĺ�����Ŀ
    for(int i=0; i<15; i++)  //�жϺ����ں�ķ������޳���
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
    for(int j=0; j<15; j++)  //�жϺ��������ķ������޳���
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
    for(int i=0; i<15; i++)  //�жϺ�����б�ķ������޳���
    {
        n=0;
        for(int ii=i, j=0; j<15&&ii<15; ii++, j++)  //�жϺ�������ϵ����µ�б�������޳��������������Σ�
        {
            if(pieces[ii][j]=='2'||pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
        n=0;
        for(int ii=0, j=i; j<15&&ii<15; ii++, j++)  //�жϺ�������ϵ����µ�б�������޳��������������Σ�
        {
            if(pieces[ii][j]=='2'||pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
        n=0;
        for(int ii=i, j=0; j<15&&ii>-1; ii--, j++)  //�жϺ�������µ����ϵ�б�������޳��������������Σ�
        {
            if(pieces[ii][j]=='2'||pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
        for(int ii=14, j=i; j<15&&ii>-1; ii--, j++)  //�жϺ�������µ����ϵ�б�������޳��������������Σ�
        {
            if(pieces[ii][j]=='2'||pieces[ii][j]=='4')
                n++;
            else n=0;
            if(n>5) return true;
        }
    }
    return false;
}
