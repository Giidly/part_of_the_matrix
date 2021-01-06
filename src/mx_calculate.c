#include "part_of_the_matrix.h"

bool mx_isCalc(int op1, int op2, enum e_Operation operation, int result)
{
	switch (operation)
	{
	case PLUS:
		if (op1 + op2 == result)
		{
			return true;
		}
		break;
	case MINUS:
		if (op1 - op2 == result)
		{
			return true;
		}
		break;
	case MULTIPLY:
		if (op1 * op2 == result)
		{
			return true;
		}
		break;
	case DIVISION:
		if (op2 == 0)
			return false;
		if (op1 / op2 == result)
		{
			return true;
		}
		break;
	case ALL:
		break;
	}
	return false;
}

bool mx_isvalidValue(const char *xxx1, const char *xxx2)
{
	char *val1 = mx_strtrim(xxx1);
	char *val2 = mx_strtrim(xxx2);
	char *val3 = mx_strnew(mx_strlen(val1));
	int diff = mx_strlen(val1) - mx_strlen(val2);
	int count = 0;
	for (int i = 0; i < diff; ++i)
	{
		val3[i] = '0';
		count++;
	}

	char *val4 = val3;
	mx_strncpy((val3 + count), val2, mx_strlen(val2));
	for (int i = 0; i < mx_strlen(val1); ++i)
	{
		if (mx_isdigit(val1[i]) && val1[i] != val4[i])
		{
			free(val4);
			return false;
		}
	}
	free(val4);
	return true;
}

void mx_calculate(t_operand *op1, t_operand *op2, enum e_Operation operation, t_operand *result, const char *argv[])
{
	char *str1 = (char *)malloc(sizeof(char) * 20);
	char *str2 = (char *)malloc(sizeof(char) * 20);
	char *str3 = (char *)malloc(sizeof(char) * 20);
	if (operation != ALL)
	{
		for (int i = op1->min; i <= op1->max; i++)
		{
			str1 = (char *)malloc(sizeof(char) * 20);
			str1 = mx_itoa(i, str1, 10);
			if (mx_isvalidValue(argv[1], str1))
			{
				for (int j = op2->min; j <= op2->max; j++)
				{
					str2 = (char *)malloc(sizeof(char) * 20);
					str2 = mx_itoa(j, str2, 10);
					if (mx_isvalidValue(argv[3], str2))
					{
						for (int k = result->min; k <= result->max; k++)
						{
							str3 = (char *)malloc(sizeof(char) * 20);
							str3 = mx_itoa(k, str3, 10);
							if (mx_isvalidValue(argv[4], str3))
							{
								if (mx_isCalc(i, j, operation, k))
								{
									mx_printint(i);
									mx_printchar(' ');
									mx_printchar((char)operation);
									mx_printchar(' ');
									mx_printint(j);
									mx_printchar(' ');
									mx_printchar('=');
									mx_printchar(' ');
									mx_printint(k);
									mx_printchar('\n');
								}
							}
							free(str3);
						}
					}
					free(str2);
				}
			}
			free(str1);
		}
	}
	else
	{
		mx_calculate(op1, op2, PLUS, result, argv);
		mx_calculate(op1, op2, MINUS, result, argv);
		mx_calculate(op1, op2, MULTIPLY, result, argv);
		mx_calculate(op1, op2, DIVISION, result, argv);
	}
}
