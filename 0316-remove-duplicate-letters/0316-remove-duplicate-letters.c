#include <string.h>

char* removeDuplicateLetters(char* s)
{
    int last[26] = {0};
    int visited[26] = {0};
    int stack[26];
    int top = -1;
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        last[s[i] - 'a'] = i;
    }
    for (i = 0; s[i] != '\0'; i++)
    {
        int current = s[i] - 'a';

        if (visited[current])
        {
            continue;
        }

        while (top >= 0 &&
               stack[top] > current &&
               last[stack[top]] > i)
        {
            visited[stack[top]] = 0;
            top--;
        }

        stack[++top] = current;
        visited[current] = 1;
    }

    for (i = 0; i <= top; i++)
    {
        s[i] = stack[i] + 'a';
    }

    s[top + 1] = '\0';
    return s;
}