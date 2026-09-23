int searchInsert(int* nums, int numsSize, int target) 
{
    int i,j;
    for(i=0;i<numsSize;i++)
    {
        if(target==nums[i])
        {
            return i;
        }
        if(target<nums[i])
        {
            return i;
        }     
    }
    return numsSize;
}