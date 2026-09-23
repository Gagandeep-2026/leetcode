bool isAnagram(char* s, char* t)
{
    int i;
    int count1=0,count2=0;
    int freq[26]={0};

    while(s[count1]!='\0')
        count1++;

    while(t[count2]!='\0')
        count2++;

    if(count1!=count2)
        return false;

    for(i=0;i<count1;i++)
    {
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }

    for(i=0;i<26;i++)
    {
        if(freq[i]!=0)
            return false;
    }

    return true;
}