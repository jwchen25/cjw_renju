#ifndef CJW_TIMER_H
#define CJW_TIMER_H
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class CJW_Timer
{
    public:
        CJW_Timer();
        virtual ~CJW_Timer();
        int second;
        void tick();
		void print();
		void run();

    protected:

    private:
};

#endif // CJW_TIMER_H
