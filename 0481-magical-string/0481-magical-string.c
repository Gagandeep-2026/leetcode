int magicalString(int n) 
{
    if(n == 0)
        return 0;

    char arr[100000];

    arr[0] = '1';

    if(n > 1)
        arr[1] = '2';

    if(n > 2)
        arr[2] = '2';

    int i = 2;
    int j = 3;
    int count = 1;

    while(j < n)
    {
        // arr[i] tells how many times
        // the next number should be added

        int times = arr[i] - '0';

        // If previous number is 1,
        // add 2. Otherwise add 1.
        char next;

        if(arr[j - 1] == '1')
            next = '2';
        else
            next = '1';

        while(times > 0 && j < n)
        {
            arr[j] = next;

            if(next == '1')
                count++;

            j++;
            times--;
        }

        i++;
    }

    return count;
}