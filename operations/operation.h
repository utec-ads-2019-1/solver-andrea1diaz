#ifndef OPERATION_H 
#define OPERATION_H 
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Operation {
    protected:
        std::string equation;
				int tooperate;
				Operation* left;
				Operation* right;

    public:
        static Operation* buildFromEquation(std::string equation);

				Operation() : left(NULL), right(NULL) {};

				Operation(std::string equation): equation(equation), left(NULL), right(NULL) {};

				Operation(Operation* left, Operation* right) : left(left), right(right) {};

        inline string name() { return equation; }

        virtual float operate() = 0;
};

#endif
