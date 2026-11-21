#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct node{
    int p1,p2,ps;
}c[100010];
LL m,ans;
int n,mins = 2e9+10,id,st,d;

bool cmp1(node x,node y)
{
    return x.p1 < y.p1;
}

int main()
{
    freopen("candy.in","r",stdin);freopen("candy.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d %d",&c[i].p1,&c[i].p2);
        c[i].ps = c[i].p1+c[i].p2;
        if(c[i].ps < mins)
        {
            id = i;
            mins = c[i].ps;
        }
    }
    if(c[id].p1 <= c[id].p2) d = c[id].p2;
    sort(c+1,c+n+1,cmp1);
    for(int i = 1 ; i <= n ; i++)
    {
        if(c[i].p1*2 > mins)
        {
            st = i;
            break;
        }
        if(m >= c[i].p1)
        {
            m -= c[i].p1;
            ans++;
        }
        else break;
    }
    if(d != 0 && m >= d)
    {
        m -= d;
        ans++;
    }
    if(m >= mins)
    {
        ans += (m/mins)*2;
        m %= mins;
    }
    for(int i = st ; i <= n ; i++)
    {
        if(m >= c[st].p1)
        {
            m -= c[st].p1;
            ans++;
        }
        else break;
    }
    printf("%lld",ans);
    return 0;
}
