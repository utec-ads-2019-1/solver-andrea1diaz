#include "operation.h"

class Plus : public Operation {
	public:
		Plus (Operation* left, Operation*	right) : Operation(left, right) {}

		virtual float operate() {
			return left->operate() + right->operate();
		}
};


class Minus : public Operation {
	public:
		Minus (Operation* left, Operation* right) : Operation (left, right) {}

		virtual float operate() {
			return left->operate() - right->operate();
		}
};

class Obelus : public Operation {
	public:
		Obelus (Operation* left, Operation* right) : Operation (left, right) {}

		virtual float operate() {
			return left->operate() / right->operate();
		}
};


class Times : public Operation {
	public:
		Times (Operation* left, Operation* right) : Operation (left, right) {}

		virtual float operate() {
			return left->operate() * right->operate();
		}
};


class Exponent : public Operation {
	public: 
		Exponent (Operation* left, Operation* right) : Operation (left, right) {}

		virtual float operate() {
			float result = 0.0;
			
			for (int i = 0; i < right->operate(); ++i) {
				result *= left->operate();
			}
		
			return result;
		}
};


class Change : public Operation {
	public: 
		Change (Operation* left) : Operation (left, NULL) {}
		
		virtual float operate() {
			return -1 * left->operate();
		}
};

