bool isPalindrome(int x)
{
    int temp=x;
    long long rev=0;
    if(x<0)
    {
        return 0;
    }
    while(x!=0)
    {  
       rev=(x%10) + (rev*10);
       x=x/10;
    }
    if(temp==rev)
    {
        return 1;

    }
    else
    {
        return 0;
    }
    
}