#ifndef OPERATION_H 
#define OPERATION_H 
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Operation {
    protected:
        std::string equation;
				int data;
				char op;
				Operation* left;
				Operation* right;

    public:
        static Operation* buildFromEquation(string equation);

				Operation(int data, char op): left(NULL), right(NULL), data(data), op(op) {};

				Operation(Operation* left, Operation* right) : left(left), right(right) {};

        inline string name() { return equation; }

        virtual float operate() = 0;
};

#endif
