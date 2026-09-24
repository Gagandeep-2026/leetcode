#include <stdbool.h>

bool isNumber(char* s)
{
    int i = 0;

    int digit = 0;
    int dot = 0;
    int exponent = 0;
    int exponentDigit = 0;

    // Sign at the beginning
    if (s[i] == '+' || s[i] == '-')
        i++;

    while (s[i] != '\0')
    {
        // Digit
        if (s[i] >= '0' && s[i] <= '9')
        {
            digit = 1;

            if (exponent)
                exponentDigit = 1;
        }

        // Decimal point
        else if (s[i] == '.')
        {
            if (dot || exponent)
                return false;

            dot = 1;
        }

        // Exponent
        else if (s[i] == 'e' || s[i] == 'E')
        {
            if (exponent || !digit)
                return false;

            exponent = 1;
            exponentDigit = 0;

            // Sign after e/E
            if (s[i + 1] == '+' || s[i + 1] == '-')
                i++;
        }

        // Anything else
        else
        {
            return false;
        }

        i++;
    }

    // There must be a digit
    if (!digit)
        return false;

    // If e/E exists, there must be a digit after it
    if (exponent && !exponentDigit)
        return false;

    return true;
}