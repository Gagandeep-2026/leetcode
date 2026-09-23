int search(int* nums, int numsSize, int target) 
{
    int i;
    int found=0;
    for(i=0;i<numsSize;i++)
    {
        found=0;
        if(nums[i]==target)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        return i;
    }
    return -1;
}