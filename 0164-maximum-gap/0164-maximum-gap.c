#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int used;
    int min;
    int max;
} Bucket;

int maximumGap(int* nums, int numsSize)
{
    if (numsSize < 2)
        return 0;

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < minVal)
            minVal = nums[i];

        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    if (minVal == maxVal)
        return 0;

    int bucketSize = (maxVal - minVal) / (numsSize - 1);
    if (bucketSize == 0)
        bucketSize = 1;

    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    Bucket *bucket = (Bucket *)malloc(bucketCount * sizeof(Bucket));

    for (int i = 0; i < bucketCount; i++)
    {
        bucket[i].used = 0;
        bucket[i].min = INT_MAX;
        bucket[i].max = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++)
    {
        int index = (nums[i] - minVal) / bucketSize;

        if (!bucket[index].used)
            bucket[index].used = 1;

        if (nums[i] < bucket[index].min)
            bucket[index].min = nums[i];

        if (nums[i] > bucket[index].max)
            bucket[index].max = nums[i];
    }

    int ans = 0;
    int prev = minVal;

    for (int i = 0; i < bucketCount; i++)
    {
        if (!bucket[i].used)
            continue;

        if (bucket[i].min - prev > ans)
            ans = bucket[i].min - prev;

        prev = bucket[i].max;
    }

    free(bucket);

    return ans;
}