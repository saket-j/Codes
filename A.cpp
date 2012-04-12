#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define inf 100000000

int main()
{
    int n, m, i, j, k;
    int cost[1001],a ,b;
    int mat[1001][1001];
    bool adj[1001][1001];
    scanf("%d%d",&n,&m);
    
    for(i=0;i<n;i++)
        scanf("%d",&cost[i]);
    
    memset(adj,0,sizeof(adj));
    
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        mat[a][0]++;
        mat[b][0]++;
        mat[a][mat[a][0]] = b;
        mat[b][mat[b][0]] = a;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    int minc = inf;
    
    for(i=1;i<=n;i++)
    {
        for(j=mat[i][0];j>=1 && mat[i][j]>i;j--)
        {
            for(k=j-1;k>=1 && mat[i][k]>i;k--)
                if(adj[mat[i][k]][mat[i][j]] == 1)
                {
                    int nc = cost[i-1]+cost[mat[i][k]-1]+cost[mat[i][j]-1];
                    minc = min(nc,minc);
                }
        }
    }
    if(minc==inf)
        printf("%d\n",-1);
    else
        printf("%d\n",minc);
}
