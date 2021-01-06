#include "part_of_the_matrix.h"

char* mx_itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
    if (isNegative) 
        str[i++] = '-'; 
    str[i] = '\0';
  
    mx_str_reverse(str); 
  
    return str; 
}
