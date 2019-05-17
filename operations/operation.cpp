#include "operation.h"
// #include "../tree.h"

static char ops[1] = {'+'};

bool is_op (char data, Operation* node) {
  switch (data) {
    case '+':
			op_plus(node);
      return true;
    default:
      return false;
  }
}

int op_plus(Operation* node) {
	int a = node->left + node->right;
	std::cout << a << std::endl;
	return node->left + node->right;
}


Operation* Operation::buildFromEquation(std::string entry){


  for (int i = 0; i < entry.length(); ++i) {
	std::cout << entry[i] << std::endl;

	Operation* node = new Operation;
	node->left = Operation::buildFromEquation(entry.substr(0, 1));
	node->right = Operation::buildFromEquation(entry.substr(2, entry.length()));
	op_plus(node);
	

  }

  std::cout << "\n----------" << '\n';
}
