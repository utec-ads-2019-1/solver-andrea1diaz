#include "operation.h"
// #include "../tree.h"
#include "get_operations.h"

static char operations[5] = {'+', '-', '*', '/', '^'};

int is_op(std::string entry, char op) {
	for (int i = 0; i < entry.length(); ++i) {
		if (entry[i] != op && entry.length() > 1) {
			return i + 1;
		}

		else return 0;
	}
}


int sign_add(std::string entry, char op) {
	return 0;
}


bool parentheses_check(std::string entry) {	
	int perentheses_count = 0;

	for (int i = 0; i < entry.length(); ++i) {
		if (entry[i] == '(') parentheses_count ++;
		else if (entry [i] == ')') parentheses_count --;
	}

	if (parentheses_count == 0) return true;
	else return false;
}


Operation* Operation::buildFromEquation(std::string entry) {
	for (int i = 0; i < operations.size(); ++i) {
		char operation = operations[i];
		int pos = is_op(entry, operation);
		
		if (pos != 0) {
			Operation* left = Operation::buildFromEquation(entry.substr(0, pos));
			Operation* right = Operation::buildFromEquation(entry.substr(pos + 1, entry.length()));
			//right->tooperate = std::stoi(entry.substr(pos + 1, entry.length()));
			//left->tooperate = std::stoi(entry.substr(0, pos));
			right->entry = entry.substr(pos + 1, entry.length());
			return GetOperations::GetOperation (operations[i], left, right);
		}

  }


}
