#include "CJW_Timer.h"

CJW_Timer::CJW_Timer()
{
    second=15;
}

CJW_Timer::~CJW_Timer()
{
    //dtor
}

void CJW_Timer::tick()
{
	Sleep(1000);
	second--;
}

void CJW_Timer::print()
{
    cout << '\r';
    if(second>9) cout << "                 You have " << second << " seconds left.";
    else          cout << "                  You have " << second << " seconds left.";
}

void CJW_Timer::run()
{
    print();
	while(second!=0)
	{
		tick();
		print();
	}
	cout<<'\a';
}
