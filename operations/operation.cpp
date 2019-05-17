#include "operation.h"
// #include "../tree.h"

struct Node {
    std::string data;
    int weight;
    Node* left;
		Node* right;
};

static char ops[1] = {'+'};

bool is_op (char data, Node* node) {
  switch (data) {
    case '+':
			op_plus(node->left, node->right);
      return true;
    default:
      return false;
  }
}

void op_plus(
Operation* Operation::buildFromEquation(std::string entry){


  for (int i = 0; i < entry.length(); ++i) {
    std::cout << entry[i] << std::endl;

  }

  std::cout << "\n----------" << '\n';
}
