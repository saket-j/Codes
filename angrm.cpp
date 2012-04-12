#include<stdio.h>
#include<string.h>
void permute(char s[], int k, int m)
{
    int i;
    char temp;
    if (k == m)
        printf("%s\n",s);
    else
    {
        for (i=k;i<m;i++)
        {
            temp = s[i];
            s[i] = s[m-1];
            s[m-1] = temp;
            
            permute(s,k,m-1);
            
            temp = s[i];
            s[i] = s[m-1];
            s[m-1] = temp;
         }
    }        
            
}

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

int nxtperm(char s[],int len)
{
   int ret = 0,i = 0,j,k;
   
   for (i = len-2; i >= 0; i--)
   {
        if (s[i+1]>s[i])
        {
            ret = 1;
            
            for (k = i+1, j = len-1; j > k; k++,j--)
                swap(s[k],s[j]);
            
            for (j = i+1; j < len; j++)
                if (s[i] < s[j])
                    break;
            swap(s[i],s[j]); 
            break;       
         }
    }
    
    return ret;    
}

int main()
{
    char s[100];
    int len;
    scanf("%s",s);
    len = strlen(s);
//    permute(s,0,len);
    while (nxtperm(s,len))
        printf("%s\n",s);
}
