#include "operation.h"

class Plus : Operation {
	public:
		Plus (Operation* left, Operation*	right) : Operation(left, right) {};

		virtual float operate() {
			float op = left->operate() + right->operate();

			return op;
		}
};
