/*
ID: curious
PROG: milk2
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first<=b.first)
        return 1;
    return 0;
}

int main() 
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    
    int n, a, b, i, ltm=0, ltn=0;
    vector<pair<int,int> > cow;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        cow.push_back(make_pair(a,b));
    }
    sort(cow.begin(),cow.end(),compare);
    int st = cow[0].first;
    int en = cow[0].second;
    ltm = en-st;
    for(i=1;i<n;i++)
    {
        if(cow[i].first>=st && cow[i].first<=en)
        {
            en = max(en,cow[i].second);
            ltm = max(ltm,en-st);
        }
        else
        {
            ltn = max(ltn,cow[i].first-en);
            st = cow[i].first;
            en = cow[i].second;
            ltm = max(ltm,en-st);
        }
    }
    printf("%d %d\n",ltm,ltn);
}
