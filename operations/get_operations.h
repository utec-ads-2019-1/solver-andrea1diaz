#include "operation.h"
#include "operations.h"

class GetOperations {
	public:
		static Operation* GetOperation (char operation, Operation* left, Operation* right) {
			switch (operation) {
				case ('+'):
					return new Plus(left, right);

				default:
					return NULL;
			}
		}
};
