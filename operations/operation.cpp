#include "operation.h"
// #include "../tree.h"

static char ops[1] = {'+'};

bool is_op (char data, Operation* node) {
  switch (data) {
    case '+':
      return true;
    default:
      return false;
  }
}

int op_plus(Operation* node) {
	int c = node->left->operate();
	std::cout << c << std::endl;
	return 0;
}


Operation* Operation::buildFromEquation(std::string entry){


  for (int i = 0; i < entry.length(); ++i) {
	std::cout << entry[i] << std::endl;

	Operation* node;
	Operation* left = Operation::buildFromEquation(entry.substr(0, 1));
	Operation* right = Operation::buildFromEquation(entry.substr(2, entry.length()));
	node->left = left;
	node->right = right;
	op_plus(node);

  }

  std::cout << "\n----------" << '\n';
}
