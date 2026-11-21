#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct node{
    int op,sp,xjb,id;
}a[5000];
LL dp[10010];
LL mod = 99824435390;

LL ksm(LL x)
{
    LL an = 1;
    LL sum = 2;
    while(true)
    {
        cout << x << endl;
        if(x%2==1) an = ((an%mod)*(sum%mod))%mod;
        sum = ((sum%mod)*(sum%mod))%mod;
        if(x == 1)break;
        x = x>>1;
    }
    return an;
}

int main()
{
    //freopen(".in","r",stdin);freopen(".out","w",stdout);
    LL m;
    scanf("%lld",&m);
    cout << ksm(m);
    return 0;
}
