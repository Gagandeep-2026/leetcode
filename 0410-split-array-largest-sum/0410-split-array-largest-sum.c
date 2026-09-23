int canSplit(int *nums, int numsSize, int k, int maxSum)
{
    int count = 1;
    int sum = 0;

    for(int i = 0; i < numsSize; i++)
    {
        if(sum + nums[i] <= maxSum)
        {
            sum += nums[i];
        }
        else
        {
            count++;
            sum = nums[i];

            if(count > k)
                return 0;
        }
    }

    return 1;
}

int splitArray(int* nums, int numsSize, int k)
{
    int low = nums[0];
    int high = 0;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] > low)
            low = nums[i];

        high += nums[i];
    }

    while(low < high)
    {
        int mid = low + (high - low) / 2;

        if(canSplit(nums, numsSize, k, mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}