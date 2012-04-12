#include <stdio.h>

int main()
{
    long long int t, n, v, nv, res;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        res=0;
        nv = n;
        while(n--)
        {
            scanf("%lld",&v);
            res = (res+v)%nv;
        }
        printf("%s\n",res!=0?"NO":"YES");
    }
}
