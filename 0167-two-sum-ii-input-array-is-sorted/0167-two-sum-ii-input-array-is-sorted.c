int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int left = 0;
    int right = numbersSize - 1;

    int *result = malloc(2 * sizeof(int));

    while(left < right)
    {
        int sum = numbers[left] + numbers[right];

        if(sum == target)
        {
            result[0] = left + 1;
            result[1] = right + 1;

            *returnSize = 2;
            return result;
        }

        if(sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    *returnSize = 0;
    free(result);
    return NULL;
}