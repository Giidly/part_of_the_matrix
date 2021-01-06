#include "part_of_the_matrix.h"

void mx_error_print(enum e_Errors ErrorCode, const char *value)
{
	switch (ErrorCode)
	{
	case INVLD_ARG:
		mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
		break;
	case INVLD_OPERATION:
		mx_printerr("Invalid operation: ");
		mx_printerr(value);
		mx_printerr("\n");
		break;
	case INVLD_OPERAND:
		mx_printerr("Invalid operand: ");
		mx_printerr(value);
		mx_printerr("\n");
		break;
	case INVLD_RES:
		mx_printerr("Invalid result: ");
		mx_printerr(value);
		mx_printerr("\n");
		break;
	}
	exit(ErrorCode);
}
