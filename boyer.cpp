#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

char s[100], text[1000];
int good[100], bad[26], l;

void Compute_good()
{
    int  i, j, k, fl;
    l = strlen(s);
    good[0]=1;
    for(i=1;i<l;i++)
    {
        fl=0;
        good[i] = good[i-1];
        for(j=l-2;j>=i-1 && !fl;j--)
        {
            fl=1;
            for(k=0;k<i;k++)
                if(s[l-1-k]!=s[j-k])
                {
                    fl=0;
                    break;
                }
             if(fl)
                good[i] = l-1-j;
        }
    }  
}

void Compute_bad()
{
    memset(bad,-1,sizeof(bad));
    int i;
    for(i=l-2;i>=0;i--)
        if(bad[s[i]-'a']<0)
            bad[s[i]-'a'] = l-1-i;
    for(i=0;i<26;i++)
        if(bad[i]<0)
            bad[i] = l;
}

int Boyer_Search()
{
    Compute_good();
    Compute_bad();
    int cs=0;
    int l2 = strlen(text), i, fl=0;
    for(i=0;i<26;i++)
        cout<<(char)('a'+i)<<' '<<bad[i]<<endl;
    for(i=0;i<l;i++)
        cout<<good[i]<<endl;
    while(cs+l<=l2 && !fl)
    {
        fl=1;
        for(i=0;i<l;i++)
            if(s[l-1-i] != text[cs+l-1-i])
            {
                fl=0;
                break;
            }
        if(fl)
            return 1;
        int bs=1;
        if(bad[text[cs+l-1-i]-'a']==l)
            bs = l-i;
        else if(bad[text[cs+l-1-i]-'a']>l-i-1)
            bs = bad[text[cs+l-1-i]-'a']-(l-i-1);
        cs += max(good[i],bs);
    }
    return 0;
}

int main()
{
    strcpy(s,"anpanman");
    strcpy(text,"wqzzxcvapsdfseapanenaanpanmandfgd");
    cout<<Boyer_Search();
}
