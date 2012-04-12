#include <stdio.h>
#include <algorithm>
using namespace std;

int Select(int *a, int n)
{
    int i, temp[100], count=0, j;
    if(n==1)
        return a[0];
    for(i=0;i<n;i+=5)
    {
        for(j=0;j<5 && i+j<n;j++)
        {
            temp[count+j] = a[i+j];
        }
        sort(temp+count,temp+count+j);
        temp[count] = temp[count+(j-1)/2];
        count++;
    }
    return Select(temp,count);
}

int MoM(int *a, int k, int n)
{
    int i=-1, ret=-1, temp[100], count, j,s;
    for(i=0;i<n;i++)
        temp[i] = a[i];
    count = n;
    do
    {
        ret = Select(temp,count);
        i=0; j=count;
        int sp = 0;
        for(s=0;s<count;s++)
        {
            if(temp[s] < ret)
                temp[i++] = temp[s];
            else if(temp[s] > ret)
                temp[j++] = temp[s];
            else
                sp++;
        }
        
        if(i<k && i+sp>=k)
            i=k;
        else if(i>k)
        {
            count = i;
        }
        else if (i+sp<k)
        {
            int t;
            for(t=0;t<j-count;t++)
                temp[t] = temp[count+t];
            
            k = k - i - sp;
            count = t; i=0;
        }
    }while(i!=k);
    
    return ret;
}

int main()
{
    int n, a[100], i=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("%d\n",MoM(a,7,n));
}
