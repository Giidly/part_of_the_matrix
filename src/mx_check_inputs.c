#include "part_of_the_matrix.h"

bool mx_checkOperation(const char* op) {
	char sign = 0;
	if (mx_strlen(op) == 0) return false;
	const char* start = op;
	const char* end = op + mx_strlen(op) - 1;
	while (mx_isspace(*end)) { 
		--end;
		}
	while (mx_isspace(*start)) { 
		++start;
		}
	if ((end - start) < 0) 
		return false;
	for (int i = 0; i < (end - start + 1); ++i) {
		if ((start[i] == '+' || start[i] == '-' || start[i] == '*' || start[i] == '/' || start[i] == '?') && !sign) {
			sign = 1;
		}
		else {
			return false;
		}
	}
	return true;
}

bool mx_checkOperand(const char* op) {
	char sign = 0;
	if (mx_strlen(op) == 0) return false;
	const char* start = op;
	const char* end = op + mx_strlen(op) - 1;
	while (mx_isspace(*end)) { 
		--end; 
		}
	while (mx_isspace(*start)) { 
		++start; 
		}
	if ((end - start) < 0) 
		return false;
	for (int i = 0; i < (end - start + 1); ++i) {
		if (!mx_isdigit(start[i]) && start[i] != '?') {
			if (i == 0 && ((start[i] == '-') || (start[i] == '+')) && !sign && (mx_isdigit(start[i + 1]) || start[i+1] == '?')) {
				sign = 1;
			}
			else {
				return false;
			}
		}
	}
	return true;
}
