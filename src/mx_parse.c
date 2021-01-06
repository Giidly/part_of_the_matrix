#include "part_of_the_matrix.h"

int mx_max(const char *str)
{
	int len = mx_strlen(str);
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '?')
		{
			max += 9 * mx_pow(10, len - 1 - i);
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			max += (str[i] - '0') * mx_pow(10, len - 1 - i);
		}
	}
	if (str[0] == '-')
	{
		return -max;
	}
	else
	{
		return max;
	}
}

int mx_min(const char *str)
{
	int len = mx_strlen(str);
	int min = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			min += (str[i] - '0') * mx_pow(10, len - 1 - i);
		}
	}
	if (str[0] == '-')
	{
		return -min;
	}
	else
	{
		return min;
	}
}

t_operand *mx_parseArg(const char *arg)
{
	char *str = mx_strtrim(arg);
	t_operand *op = (t_operand *)malloc(sizeof(t_operand));
	op->max = mx_max(str);
	op->min = mx_min(str);
	if (op->min > op->max)
	{
		int tmp = op->min;
		op->min = op->max;
		op->max = tmp;
	}
	free(str);
	return op;
}

enum e_Operation mx_parseOper(const char *operation)
{
	char *str = mx_strtrim(operation);
	if (str[0] == '+')
	{
		free(str);
		return PLUS;
	}
	if (str[0] == '-')
	{
		free(str);
		return MINUS;
	}
	if (str[0] == '*')
	{
		free(str);
		return MULTIPLY;
	}
	if (str[0] == '/')
	{
		free(str);
		return DIVISION;
	}
	if (str[0] == '?')
	{
		free(str);
		return ALL;
	}
	return -1;
}

t_operand **mx_parse(const char *arg1, const char *arg2, const char *res)
{
	t_operand **op = (t_operand **)malloc(sizeof(t_operand *) * 3);
	op[0] = mx_parseArg(arg1);
	op[1] = mx_parseArg(arg2);
	op[2] = mx_parseArg(res);
	return op;
}
