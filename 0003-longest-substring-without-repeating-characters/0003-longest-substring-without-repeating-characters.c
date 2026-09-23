int lengthOfLongestSubstring(char* s)
{
    int i, j;
    int count = 0;
    int max = 0;

    while(s[count] != '\0')
    {
        count++;
    }

    for(i = 0; i < count; i++)
    {
        int found[256] = {0};
        int current = 0;

        for(j = i; j < count; j++)
        {
            if(found[(unsigned char)s[j]] == 1)
            {
                break;
            }

            found[(unsigned char)s[j]] = 1;
            current++;
        }

        if(current > max)
        {
            max = current;
        }
    }
    return max;
}