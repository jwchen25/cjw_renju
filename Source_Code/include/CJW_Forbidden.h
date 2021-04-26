#ifndef CJW_FORBIDDEN_H
#define CJW_FORBIDDEN_H
#include <iostream>
using namespace std;

class CJW_Forbidden
{
    public:
        CJW_Forbidden();
        virtual ~CJW_Forbidden();
        bool Live_Three(int line[9]);  //判断某条线中有没有活三(五子棋术语)
        bool Four(int line[9]);  //判断某条线中有没有四(五子棋术语)
        bool Forbidden1(char pieces[15][15]);  //判断是否为三三禁手或四四禁手
        bool Forbidden2(char pieces[15][15]);  //判断是否为长连禁手

    protected:

    private:
};

#endif // CJW_FORBIDDEN_H
