#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) 
{
    int count1=0;
    int count2=0;

    while(num1[count1])
        count1++;

    while(num2[count2])
        count2++;

    if((count1==1 && num1[0]=='0') || (count2==1 && num2[0]=='0'))
    {
        char *result=malloc(2);
        result[0]='0';
        result[1]='\0';
        return result;
    }

    int *arr=calloc(count1+count2,sizeof(int));

    int i,j;

    for(i=count1-1;i>=0;i--)
    {
        for(j=count2-1;j>=0;j--)
        {
            int n1=num1[i]-'0';
            int n2=num2[j]-'0';

            int pos1=i+j;
            int pos2=i+j+1;

            int multi=n1*n2+arr[pos2];

            arr[pos2]=multi%10;
            arr[pos1]+=multi/10;
        }
    }

    char *str=malloc(count1+count2+1);

    i=0;
    j=0;

    while(i<count1+count2 && arr[i]==0)
        i++;

    while(i<count1+count2)
    {
        str[j]=arr[i]+'0';
        i++;
        j++;
    }

    str[j]='\0';

    free(arr);

    return str;
}