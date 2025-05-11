#include "Calculator.h"

// Default constructor.
Calculator::Calculator()
{
    numbers.clear();
    numbers.push_back(INFINITY);
    numbers.push_back(INFINITY);
    operation = ' ';
    done = false;
}

// Empties the vector and resets the values to infinity.
void Calculator::setVector()
{
    numbers.clear();
    numbers.push_back(INFINITY);
    numbers.push_back(INFINITY);
}


// Gets user input to determine first value of the numbers vector.
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

// Sets the first value of the numbers vector to the given double.
// Used mainly to continue an answer into the next equation.
void Calculator::setFirstNumber(double result)
{
    numbers[0] = result;
}

// Return the first value of the numbers vector.
double Calculator::getFirstNumber()
{
    return numbers.front();
}

// Gets user input to set the second value in the numbers vector.
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

// Return the second number of the numbers vector.
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

// Return the operation that was selected.
char Calculator::getOperation()
{
    return operation;
}

// Multiplication operation.
void Calculator::performMultiplication()
{
    double result = getFirstNumber() * getSecondNumber();
    setFirstNumber(result);
    displayAnswer();
    reset();
}

// Division operation.
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

// Addition operation.
void Calculator::performAddition()
{
    double result = getFirstNumber() + getSecondNumber();
    setFirstNumber(result);
    displayAnswer();
    reset();
}

// Subtraction operation.
void Calculator::performSubtraction()
{
    double result = getFirstNumber() - getSecondNumber();
    setFirstNumber(result);
    displayAnswer();
    reset();
}

// Exponent operation.
void Calculator::performExponent()
{
    double result = pow(getFirstNumber(), getSecondNumber());
    setFirstNumber(result);
    displayAnswer();
    reset();
}

// Output the answer.
void Calculator::displayAnswer()
{
    cout << "Answer is: " << getFirstNumber() << "\n";
}

// identify the operation that was selected and go to that equation, or clear all inputs, or exit the program.
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

// Return done.
bool Calculator::getDone()
{
    return done;
}

// Remove all values inputed but keep the first as the new result for future inputs.
void Calculator::reset()
{
    if (numbers.size() > 1) {
        for (int i = 0; numbers.size() - 1; i++) {
            numbers.pop_back();
        }
    }
    numbers.push_back(INFINITY);
}

// Remove all user inputed values and reset the vector.
void Calculator::clear()
{
    setVector();
}

// Set done to true to exit the program.
void Calculator::quit()
{
    done = true;
}