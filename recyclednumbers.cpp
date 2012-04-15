#include <stdio.h>
#include <set>
using namespace std;

int countpairs(int a, int b, int v)
{
    int val=v, l=0, i, t, m=1;
    set<int> s;
    while(val)
    {
        l++;
        val/=10;
        m*=10;
    }
    val = v;
    m/=10;
    for(i=1;i<l;i++)
    {
        t = val%10;
        val/= 10;
        val = t*m + val;
        if(val>=a && val<=b && val>v)
        {
            s.insert(val);
            //printf("%d %d\n",v,val);
        }
    }
    return s.size();
}

int main()
{
    int t,c, a, b, count,i;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d%d",&a,&b);
        count=0;
        for(i=a;i<=b;i++)
            count += countpairs(a,b,i);
        printf("Case #%d: %d\n",c,count);
    }
}
