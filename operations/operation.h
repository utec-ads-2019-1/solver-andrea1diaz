#ifndef OPERATION_H 
#define OPERATION_H 
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Operation {
    protected:
        std::string entry;
				int tooperate;
				Operation* left;
				Operation* right;

    public:
        static Operation* buildFromEquation(std::string entry);

				Operation() : left(NULL), right(NULL) {};

				Operation(int tooperate): tooperate(tooperate) {};

				Operation(Operation* left, Operation* right) : left(left), right(right) {};

        inline string name() { return entry; }

        virtual float operate() = 0;
};

#endif
