#ifndef CJW_CHESSBOARD_H
#define CJW_CHESSBOARD_H
#include <iostream>
#include <string>
using namespace std;

class CJW_Chessboard
{
    public:
        CJW_Chessboard();
        virtual ~CJW_Chessboard();
        void Rewrite_SizeofBoard(int n); //�޸����̴�С
        void Board_print(char chess[15][15], int Cx, int Cy); //����У��
    protected:

    private:
        int Chessboard_size;
};






#endif // CJW_CHESSBOARD_H
