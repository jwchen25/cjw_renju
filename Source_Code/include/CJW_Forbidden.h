#ifndef CJW_FORBIDDEN_H
#define CJW_FORBIDDEN_H
#include <iostream>
using namespace std;

class CJW_Forbidden
{
    public:
        CJW_Forbidden();
        virtual ~CJW_Forbidden();
        bool Live_Three(int line[9]);  //�ж�ĳ��������û�л���(����������)
        bool Four(int line[9]);  //�ж�ĳ��������û����(����������)
        bool Forbidden1(char pieces[15][15]);  //�ж��Ƿ�Ϊ�������ֻ����Ľ���
        bool Forbidden2(char pieces[15][15]);  //�ж��Ƿ�Ϊ��������

    protected:

    private:
};

#endif // CJW_FORBIDDEN_H
