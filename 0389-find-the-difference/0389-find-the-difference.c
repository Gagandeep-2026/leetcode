char findTheDifference(char* s, char* t)
{
    int i, j, k = 0;
    int count1 = 0;
    int count2 = 0;
    int found;
    int digitcount[256] = {0};
    while(s[count1])
    {
        count1++;
    }
    while(t[count2])
    {
        count2++;
    }
    char str[count2 + 1];
    for(i = 0; i < count1; i++)
    {
        digitcount[(unsigned char)s[i]]++;
    }
    for(i = 0; i < count2; i++)
    {
        digitcount[(unsigned char)t[i]]--;
    }
    for(i = 0; i < 256; i++)
    {
        if(digitcount[i] < 0)
        {
            str[k] = (char)i;
            k++;
        }
    }
    str[k] = '\0';
    return str[0];
}