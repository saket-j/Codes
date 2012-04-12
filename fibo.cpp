#include <stdio.h>

long long fibo(int n)
{
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
    long long ra = 1;
    long long rb = 1;
    long long a = 1;
    long long b = 1;
    long long d = 0;
    n-=2;
    while(n)
    {
        if(n%2==1)
        {
            long long ta = a*ra + b*rb;
            long long tb = b*ra + d*rb;
            ra = ta;
            rb = tb;
            n--;
        }
        else
        {
            long long ta = a*a + b*b;
            long long tb = a*b + b*d;
            d = b*b + d*d;
            a = ta;
            b = tb;
            n /= 2;
        }   
    }
    return ra;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",fibo(n));
}
