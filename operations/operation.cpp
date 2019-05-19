#include "operation.h"
// #include "../tree.h"
#include "./op_plus.h"

static char ops[1] = {'+'};

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


Operation* Operation::buildFromEquation(std::string entry) {
for (int i = 0; i < 1; ++i) {
	int pos = is_op(entry, ops[i]);
	cout << "pos->" << pos << std::endl;
	if (pos != NULL) {
		cout << "here" << std::endl;
		Operation* l = Operation::buildFromEquation(entry.substr(0, pos));
		Operation* r = Operation::buildFromEquation(entry.substr(pos + 1, entry.length()));

		std::cout << "result" << std::endl;
	}
		
	//std::cout << entry << std::endl;
//  for (int i = 0; i < 1; ++i) {
//		int pos = is_op(entry, ops[0]);
//
//		if (pos) {
//			//std::cout << entry.substr(0, 1) << " - " << entry.substr(2, entry.length()) << std::endl;
//			std::cout << pos << " her" << std::endl;
//			Operation* node;
//			Operation* left = entry.substr(0, pos);
//			node->right = entry.substr(pos + 1, entry.length());
//	
//			Plus(node->left, node->right);
//			std::cout << node->left->operate() + node->right->operate() << std::endl;
		//}
  }

  std::cout << "\n----------" << '\n';
}
