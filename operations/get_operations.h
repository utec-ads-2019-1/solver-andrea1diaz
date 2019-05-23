#include "operation.h"
#include "operations.h"
#include "constant.h"

class GetOperations {
	public:
		static Operation* GetOperation (char operation, Operation* left, Operation* right) {
			switch (operation) {
				case ('+'):
					return new Plus(left, right);
				
				case ('-'):
					return new Minus(left, right);

				case ('*'):
					return new Times(left, right);

				case ('/'):
					return new Obelus(left, right);

				case ('^'):
					return new Exponent(left, right);

				default:
					return NULL;
			}
		}


		static Operation* ChangeSign(Operation* left) {
			return new Change(left);
		}


		static Operation* number(std::string entry) {
			return new Constant(entry);
		}
};
