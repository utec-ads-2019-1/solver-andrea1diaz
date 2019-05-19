#include "operation.h"
// #include "../tree.h"
#include "./op_plus.h"

static char ops[1] = {'+'};

int is_op(std::string entry, char op) {
	for (int i = 0; i < entry.length(); ++i) {
		if (entry[i] != op) {
			return i + 1;
		}

		else return i;
	}
}


int op_plus(Operation* node) {
	//int c = node->left->operate();
	//std::cout << c << std::endl;
	return 0;
}


Operation* Operation::buildFromEquation(std::string entry) {
	//std::cout << entry << std::endl;
  for (int i = 0; i < 1; ++i) {
		int pos = is_op(entry, ops[i]);

		if (pos) {
			//std::cout << entry.substr(0, 1) << " - " << entry.substr(2, entry.length()) << std::endl;
			Operation* left = Operation::buildFromEquation(entry.substr(0, pos));
			Operation* right = Operation::buildFromEquation(entry.substr(pos + 1, entry.length()));
	
			 Plus(left, right);
		}
  }

  std::cout << "\n----------" << '\n';
}
