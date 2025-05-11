#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>

class Calculator {
    private:
        std::vector<double> numbers;
        char operation;
        bool done;
    public:
        Calculator();
        void setVector();
        void setFirstNumber();
        void setFirstNumber(double result);
        double getFirstNumber();
        void setSecondNumber();
        double getSecondNumber();
        void setOperation();
        char getOperation();
        void performMultiplication();
        void performDivision();
        void performAddition();
        void performSubtraction();
        void performExponent();
        void displayAnswer();
        void calculate();
        bool getDone();
        void reset();
        void clear();
        void quit();
};