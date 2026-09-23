#include <stdlib.h>

int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize)
{
    int i, j, t;
    int k = 0;

    int *arr = (int *)malloc(nums1Size * sizeof(int));

    for(i = 0; i < nums1Size; i++)
    {
        int found = 0;

        for(j = 0; j < nums2Size; j++)
        {
            if(nums1[i] == nums2[j])
            {
                found = 1;
                break;
            }
        }

        if(found == 1)
        {
            int duplicate = 0;

            for(t = 0; t < k; t++)
            {
                if(arr[t] == nums1[i])
                {
                    duplicate = 1;
                    break;
                }
            }

            if(duplicate == 0)
            {
                arr[k] = nums1[i];
                k++;
            }
        }
    }

    *returnSize = k;

    return arr;
}