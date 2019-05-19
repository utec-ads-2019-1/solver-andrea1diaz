#ifndef OPERATION_H 
#define OPERATION_H 
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Operation {
    protected:
        std::string equation;
				int weight;
				Operation* left;
				Operation* right;

    public:
				Operation (Operation* left, Operation* right) : left(left) , right(right) {};
        static Operation* buildFromEquation(string equation);

        inline string name() { return equation; }

        virtual float operate() = 0;
};

#endif
