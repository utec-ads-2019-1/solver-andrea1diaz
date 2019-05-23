#include "operation.h"

class Constant : public Operation {
	public:
		Constant (std::string entry) : Operation () { equation = entry;}

		virtual float operate() {
			return std::stoi(equation);
		}
};
