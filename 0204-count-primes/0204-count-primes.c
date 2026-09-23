#include <stdlib.h>

int countPrimes(int n)
{
    if (n <= 2)
        return 0;

    char *composite = (char *)calloc(n, sizeof(char));

    if (composite == NULL)
        return 0;

    int count = 1;   // prime number 2

    // Process only odd numbers
    for (int i = 3; i < n; i += 2)
    {
        if (composite[i] == 0)
        {
            count++;

            // Start marking from i*i
            if (i <= (n - 1) / i)
            {
                for (int j = i * i; j < n; j += 2 * i)
                {
                    composite[j] = 1;
                }
            }
        }
    }

    free(composite);

    return count;
}