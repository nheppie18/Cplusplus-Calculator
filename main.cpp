#include "Calculator.h"
#include <iostream>

int main()
{
    Calculator c = Calculator();
    c.setFirstNumber();
    while (c.getDone() == false)
    {
        if (c.getFirstNumber() == INFINITY)
        {
            c.setFirstNumber();
        }
        c.setOperation();
        c.setSecondNumber();
        c.calculate();
        
    }
    cout << "Thanks for using my calculator." << endl;
}