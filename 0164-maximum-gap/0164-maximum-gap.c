#include <stdlib.h>

int maximumGap(int* nums, int numsSize)
{
    if (numsSize < 2)
        return 0;

    // Find minimum and maximum
    int min = nums[0];
    int max = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < min)
            min = nums[i];

        if (nums[i] > max)
            max = nums[i];
    }

    if (min == max)
        return 0;

    // Bucket size
    int gap = (max - min + numsSize - 2) / (numsSize - 1);

    int bucketCount = (max - min) / gap + 1;

    int *bucketMin = (int *)malloc(bucketCount * sizeof(int));
    int *bucketMax = (int *)malloc(bucketCount * sizeof(int));
    int *used = (int *)calloc(bucketCount, sizeof(int));

    // Initialize buckets
    for (int i = 0; i < bucketCount; i++)
    {
        bucketMin[i] = 0;
        bucketMax[i] = 0;
    }

    // Put values into buckets
    for (int i = 0; i < numsSize; i++)
    {
        int index = (nums[i] - min) / gap;

        if (!used[index])
        {
            bucketMin[index] = nums[i];
            bucketMax[index] = nums[i];
            used[index] = 1;
        }
        else
        {
            if (nums[i] < bucketMin[index])
                bucketMin[index] = nums[i];

            if (nums[i] > bucketMax[index])
                bucketMax[index] = nums[i];
        }
    }

    // Find maximum gap between buckets
    int maxGap = 0;
    int previous = min;

    for (int i = 0; i < bucketCount; i++)
    {
        if (!used[i])
            continue;

        int currentGap = bucketMin[i] - previous;

        if (currentGap > maxGap)
            maxGap = currentGap;

        previous = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(used);

    return maxGap;
}