#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int t,c,i,n,s,p;
    int pnts[110];
    
    int cbs, cb;
    
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d%d%d",&n,&s,&p);
        for(i=0;i<n;i++)
            scanf("%d",&pnts[i]);
        cbs = cb = 0;
        for(i=0;i<n;i++)
        {
            if((pnts[i] == p+p-2+p-1 || pnts[i] == p+p-2+p-2) && pnts[i]>=p)
            {
                cbs++;
                pnts[i] = -1000;
            }
        }
        cb += min(s,cbs);
        s = max(0,s-cbs);
        for(i=0;i<n;i++)
        {
            if(pnts[i]>=p+p-2+p-2 && pnts[i]>=p)
            {
                //printf("%d\n",pnts[i]);
                cb++;
            }
        }
        printf("Case #%d: %d\n",c,cb);
    }
}
