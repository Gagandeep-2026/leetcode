int missingNumber(int* nums, int numsSize)
{
    int i, j;

    int arr2[numsSize + 1];

    for(i = 0; i <= numsSize; i++)
    {
        arr2[i] = i;
    }
    for(i = 0; i <= numsSize; i++)
    {
        int count = 0;

        for(j = 0; j < numsSize; j++)
        {
            if(arr2[i] == nums[j])
            {
                count = 1;
                break;
            }
        }

        if(count == 0)
        {
            return arr2[i];
        }
    }

    return -1;
}