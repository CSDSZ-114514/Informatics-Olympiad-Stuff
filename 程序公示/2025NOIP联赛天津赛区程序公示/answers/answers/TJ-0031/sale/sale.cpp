#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct node{
    int op,sp,xjb,id;
}a[5000];

LL dp[10010];
LL mod = 998244353;
LL ans;
int n,m;

bool cmp(node x,node y)
{
    if(x.xjb == y.xjb)
    {
        if(x.op == y.op) return x.id < y.id;
        else return x.op > y.op;
    }
    return x.xjb > y.xjb;
}

void dfs(int d)
{
    if(d == n+1)
    {
        memset(dp,0,sizeof(dp));
        for(int i = 1 ; i <= m ; i++)
        {
            dp[i] = max(dp[i],dp[i-a[i].sp]+a[i].op);
        }
    }
}

LL ksm(LL x)
{
    LL an = 1;
    LL sum = 2;
    while(true)
    {
        if(x%2==1) an = ((an%mod)*(sum%mod))%mod;
        sum = ((sum%mod)*(sum%mod))%mod;
        if(x == 1)break;
        x = x>>1;
    }
    return an;
}

int main()
{
    freopen("sale.in","r",stdin);freopen("sale.out","w",stdout);
    int c,T;
    scanf("%d %d",&c,&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d %d",&n,&m);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d",&a[i].op);
        }
        //dfs(1);
        ans = ksm(n);
        printf("%lld\n",ans);
    }
    return 0;
}
