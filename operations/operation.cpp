#include "operation.h"
// #include "../tree.h"
#include "./op_plus.h"

static char operations[1] = {'+'};

int is_op(std::string entry, char op) {
	cout << "entry->" << entry << std::endl;
	for (int i = 0; i < entry.length(); ++i) {
		if (entry[i] != op && entry.length() != 1) {
			return i + 1;
		}

		else return NULL;
	}
}


int op_plus(Operation* node) {
	//int c = node->left->operate();
	//std::cout << c << std::endl;
	return 0;
}


Operation* getOperation(char operation, Operation* equation) {
	switch (operation) {
		case ('+'): 
			return new Plus(equation->left, equation->right);
		default:
			return (-1);
	}
}


Operation* Operation::buildFromEquation(std::string entry) {
	for (int i = 0; i < 1; ++i) {
		char operation = operations[i];
		int pos = is_op(entry, ops[i]);
	
		if (pos != NULL) {
			cout << "here" << std::endl;
			Operation* l = Operation::buildFromEquation(entry.substr(0, pos));
			Operation* r = Operation::buildFromEquation(entry.substr(pos + 1, entry.length()));
			
			Operation* pass(l, r);
			std::cout << "result " << l->operate() << std::endl;
			return getOperation(operation, pass);
		}
		
  }

  std::cout << "\n----------" << '\n';
}
