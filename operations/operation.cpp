#include "operation.h"
#include "get_operations.h"

char operations[5] = {'+', '-', '*', '/', '^'};

int is_op(std::string entry, char op) {
	for (int i = 0; i < entry.length(); ++i) {
		if (entry[i] == op) {
			if (entry[i - 1] != op && entry.length() > 1) {
				return i;
			}

			else return 0;
		}
	}
}


int sign_add(std::string entry, char op) {
	return 0;
}


std::vector<int> parentheses_check(std::string entry) {	
	int parentheses_count = 0;
	std::vector<int> open_p;
	std::vector<int> close_p;
	std::vector<int> positions;

	for (int i = 0; i < entry.length(); ++i) {
		if (entry[i] == '(') {
			parentheses_count ++;
			open_p.push_back(i);
		}	
		
		else if (entry [i] == ')') {
			parentheses_count --;
			close_p.push_back(i); 
		}
	}


	if (parentheses_count == 0) {
		for (int i = 0; i < open_p.size(); i++) {
			positions.push_back(open_p[i]);
			positions.push_back(close_p[i]);
		}

		return positions;
	}

	else return vector<int>();
}


Operation* Operation::buildFromEquation(std::string entry) {
	for (int i = 0; i < 5	; ++i) {
		char operation = operations[i];
		int pos = is_op(entry, operation);
		
		if (pos != 0) {
			Operation* left = Operation::buildFromEquation(entry.substr(0, pos));
			Operation* right = Operation::buildFromEquation(entry.substr(pos + 1, entry.length()));
			return GetOperations::GetOperation (operation, left, right);
		}
	}
	
	return GetOperations::number(entry);

}
