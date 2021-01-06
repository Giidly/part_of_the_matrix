#ifndef PART_OF_THE_MATRIX_HEADER
#define PART_OF_THE_MATRIX_HEADER

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


typedef struct s_operand {
    int min;
    int max;
    const char *value;
} t_operand;

enum e_Operation {
    PLUS = '+',
    MINUS = '-',
    MULTIPLY = '*',
    DIVISION = '/',
    ALL = '?'
};

enum e_Errors {
    INVLD_ARG,
    INVLD_OPERATION,
    INVLD_OPERAND,
    INVLD_RES
};

char *mx_strtrim(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_max(const char* str);
int mx_min(const char* str);
double mx_pow(double n, unsigned int pow);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
bool mx_checkOperand(const char* op);
bool mx_checkOperation(const char* op);
char* mx_itoa(int num, char* str, int base);
bool mx_isvalidValue(const char *xxx1, const char *xxx2);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
void mx_str_reverse(char *s);
void mx_swap_char(char *s1,char *s2);
char *mx_strncpy(char *dst, const char *src, int len);
t_operand *mx_parseArg(const char *arg);
t_operand** mx_parse(const char* arg1, const char* arg2, const char* res);
enum e_Operation mx_parseOper(const char *operation);
bool mx_isCalc(int operand1, int operand2, enum e_Operation operation, int result);
void mx_calculate(t_operand *operand1, t_operand *operand2, enum e_Operation operation, t_operand *result, const char *argv[]);
void mx_error_print(enum e_Errors ErrorCode, const char* value);

#endif
