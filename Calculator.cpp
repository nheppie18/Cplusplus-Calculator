#include "Calculator.h"

Calculator::Calculator()
{
    numbers.clear();
    numbers.push_back(INFINITY);
    numbers.push_back(INFINITY);
    operation = ' ';
    done = false;
}

void Calculator::setVector() 
{
    numbers.clear();
    numbers.push_back(INFINITY);
    numbers.push_back(INFINITY);
}

void Calculator::setFirstNumber()
{
    numbers[0] = INFINITY;
    double number;
    while (numbers[0] == INFINITY)
    {
        cout << "Please enter a number: ";
        if (cin >> number)
        {
            numbers[0] = number;
        }

        else
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "that is not a valid number." << endl;
        }
    }
}

void Calculator::setFirstNumber(double result)
{
    numbers[0] = result;
}

double Calculator::getFirstNumber()
{
    return numbers.front();
}

void Calculator::setSecondNumber()
{
    numbers[1] = INFINITY;
    double number;
    if (getDone() || getFirstNumber() == INFINITY)
    {
        return;
    }
    while (numbers[1] == INFINITY)
    {
        cout << "Please enter another number: ";
        if (cin >> number)
        {
            numbers[1] = number;
        }

        else
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "that is not a valid number." << endl;
        }
    }
}

double Calculator::getSecondNumber()
{
    return numbers.at(1);
}

void Calculator::setOperation()
{
    operation = ' ';
    while (operation == ' ')
    {
        cout << "Choose an operation: x, /, +, -, e for exponent, c to clear, or q to quit: ";
        cin >> operation;
        
        if (operation != 'x' && operation != '/' && operation != '+'
         && operation != '-' && operation != 'e' && operation != 'c' && operation != 'q')
        {
            cout << "Please choose a valid operation." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            operation = ' ';
        }
        
        if (operation == 'q' || operation == 'c')
        {
            calculate();
        }
    }
}

char Calculator::getOperation()
{
    return operation;
}

void Calculator::performMultiplication()
{
    double result = getFirstNumber() * getSecondNumber();
    setFirstNumber(result);
    displayAnswer();
    reset();
}

void Calculator::performDivision()
{
    while (getSecondNumber() == 0)
    {
        cout << "Cant't divide by 0" << endl;
        setSecondNumber();
    }
    
    double result = getFirstNumber() / getSecondNumber();
    setFirstNumber(result);
    displayAnswer();
    reset();
}

void Calculator::performAddition()
{
    double result = getFirstNumber() + getSecondNumber();
    setFirstNumber(result);
    displayAnswer();
    reset();
}

void Calculator::performSubtraction()
{
    double result = getFirstNumber() - getSecondNumber();
    setFirstNumber(result);
    displayAnswer();
    reset();
}

void Calculator::performExponent()
{
    double result = pow(getFirstNumber(), getSecondNumber());
    setFirstNumber(result);
    displayAnswer();
    reset();
}

void Calculator::displayAnswer()
{
    cout << "Answer is: " << getFirstNumber() << "\n";
}

void Calculator::calculate()
{
    switch (getOperation())
    {
        case 'x':
        {
            performMultiplication();
            break;
        }

        case '/':
        {
            performDivision();
            break;
        }

        case '+':
        {
            performAddition();
            break;
        }

        case '-':
        {
            performSubtraction();
            break;
        }

        case 'e':
        {
            performExponent();
            break;
        }

        case 'c':
        {
            clear();
            break;
        }

        case 'q':
        {
            quit();
            break;
        }
    }
}

bool Calculator::getDone()
{
    return done;
}

void Calculator::reset()
{
    if (numbers.size() > 1) {
        for (int i = 0; numbers.size() - 1; i++) {
            numbers.pop_back();
        }
    }
    numbers.push_back(INFINITY);
}

void Calculator::clear()
{
    setVector();        
}

void Calculator::quit()
{
    done = true;
}