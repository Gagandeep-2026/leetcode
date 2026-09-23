#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2)
{
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int k = 0;
    int carry = 0;

    int max = (i > j ? i : j) + 2;

    char *str = malloc(max + 1);

    while(i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if(i >= 0)
            sum += num1[i--] - '0';

        if(j >= 0)
            sum += num2[j--] - '0';

        str[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    str[k] = '\0';

    for(i = 0, j = k - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}