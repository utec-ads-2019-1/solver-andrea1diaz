#include "operation.h"
#include "get_operations.h"

char operations[5] = {'+', '-', '*', '/', '^'};
char signs[2] = {'+', '-'};

std::vector<int> parentheses_check(std::string entry);


int is_op(std::string entry, char op) {
	int p_count = 0;
	vector<int>p = parentheses_check(entry);

	for (int i = 0; i < entry.length(); ++i) {
		if (entry[i] == '(')  {
			p_count ++;
		}

		else if (entry[i] == ')') p_count --;

		else if (entry[i] == op) {
			if (entry[i - 1] != op && p_count == 0) {
				return i;
			}

			else return 0;
		}
	}

	
}


std::string sign_add(std::string entry) {
	bool next = true;

	while (next) {
			if  (entry[0] == '-' && entry[1] == '-')
				entry = '-' + entry.substr(2, entry.length());

			else if (entry[0] == '-' && entry[1] == '+')
				entry = '-' + entry.substr(2, entry.length());

			else if (entry[0] == '+')
				entry = entry.substr(1, entry.length());

			else if (entry[0] == '+' && entry[1] == '+')
				entry = entry.substr(2, entry.length());

			else if (entry[0] == '+' && entry[1] == '-')
				entry = '-' + entry.substr(2, entry.length());

			else next = false;
		}

		return entry;
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
	entry = sign_add(entry);
	for (int i = 0; i < 5	; ++i) {
		char operation = operations[i]; int pos = is_op(entry, operation); vector<int> parentheses = parentheses_check(entry); 
		if (pos != 0) {
			Operation* left = Operation::buildFromEquation(entry.substr(0, pos));
			Operation* right = Operation::buildFromEquation(entry.substr(pos + 1, entry.length()));
			return GetOperations::GetOperation (operation, left, right);
		}
	}

	for (int i = 0; i < 1; ++i) {
		char sign = signs[i];
		int pos = is_op(entry, sign);
		
		if (pos != 0) {
			Operation* left = Operation::buildFromEquation(entry.substr(1, entry.length()));
			return GetOperations::ChangeSign(left);
		}
	}

	if (entry[0] == '(' && entry[entry.length() - 1] == ')') {
		cout << "what->" << entry << endl;
		return Operation::buildFromEquation(entry.substr(1, entry.length() - 1));
	}
	
	return GetOperations::number(entry);

}
