#include "part_of_the_matrix.h"


int main(int argc, char const *argv[])
{
	if (argc != 5)
		mx_error_print(INVLD_ARG, 0);
	if (!mx_checkOperation(argv[2]))
		mx_error_print(INVLD_OPERATION, argv[2]);
	if (!mx_checkOperand(argv[1]))
		mx_error_print(INVLD_OPERAND, argv[1]);
	if (!mx_checkOperand(argv[3]))
		mx_error_print(INVLD_OPERAND, argv[3]);
	if (!mx_checkOperand(argv[4]))
		mx_error_print(INVLD_RES, argv[4]);
	t_operand **parsed = mx_parse(argv[1], argv[3], argv[4]);
	enum e_Operation operation = mx_parseOper(argv[2]);
	mx_calculate(parsed[0], parsed[1], operation, parsed[2], argv);
	return 0;
}
