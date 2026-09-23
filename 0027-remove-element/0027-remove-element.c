int removeElement(int* nums, int numsSize, int val) 
{
    int i,k=0;
    for(i=0;i<numsSize;i++)
    {
        int found=0;
        if(nums[i]==val)
        {
            found=1;
        }
        if(found==0)
        {
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}