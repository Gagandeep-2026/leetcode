double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int i,j;
    int n=nums1Size+nums2Size;
    int arr[n];
    for(i=0;i<nums1Size;i++)
    {
        arr[i]=nums1[i];
    }    
    for(j=0;j<nums2Size;j++)
    {
        arr[nums1Size+j]=nums2[j];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    if(n%2==0)
    {
        return (double)(arr[(n/2)-1]+arr[n/2])/2.0;
    }
    else
    {
        return arr[n/2]; 
    }

}