char* removeKdigits(char* num, int k) 
{
    int i, j, l = 0;
    int count = 0;
    int found = 0;

    while(num[count])
    {
        count++;
    }

    char str[count + 1];

    for(i = 0; i < count; i++)
    {
        int flag = 0;

        while(l > 0 && str[l - 1] > num[i] && k > 0)
        {
            l--;
            k--;
            flag = 1;
        }
        str[l] = num[i];
        l++;
    }
    l = l - k;

    str[l] = '\0';
    for(i = 0; i < l; i++)
    {
        num[i] = str[i];
    }
    num[l] = '\0';
    i = 0;

    while(num[i] == '0' && num[i + 1] != '\0')
    {
        i++;
    }
    if(i > 0)
    {
        j = 0;

        while(num[i])
        {
            num[j] = num[i];
            i++;
            j++;
        }
        num[j] = '\0';
    }
    if(num[0] == '\0')
    {
        num[0] = '0';
        num[1] = '\0';
    }
    return num;
}