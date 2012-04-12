#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define mod 1000000007

long long comp(int count)
{
    long long ans=26;
    for(int i=2;i<=count;i++)
        ans = (ans*26)%mod;
    return ans;
}

int calshift(int i, int n)
{
    if(i%2==0)
        return -i/2;
    int v = (n-i)/2;
    if(n%2==0)
        return v+1;
    return v;
}

int main()
{
    int n,t,i,j,count;
    int arr[100001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        count=0;
        memset(arr,0,sizeof(arr));
        
        for(i=1;i<=n;i+=2)
            if(arr[i]==0)
            {
                count++;
                arr[i]=1;
                j=i;
                //printf("%d ",j);
                while(calshift(j,n)!=0)
                {
                    j += calshift(j,n);
                    arr[j] = 1;
                    //printf("%d ",j);
                    if(i==j)
                        break;
                }
            }
              
        printf("%lld\n",comp(count));
    }
}
