#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=50005;
int a[N],n,q,sum[N];
unsigned int ans[N];

unsigned int ask(int l,int r)
{
    memset(ans,0,sizeof(ans));
    unsigned int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int len=l;len<=r;len++)
        {
            for(int st=max(1LL,i-len+1);st<=i;st++)
            {
                int ed=st+len-1;
                if(ed>n) continue;
                ans[i]=max(ans[i],(unsigned long long)sum[ed]-sum[st-1]);
            }
        }
        res^=(i*ans[i]);
       
    }
    return res;
}
signed main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<ask(l,r)<<endl;
    }
}
/*
再见，OI。
感谢你三年的陪伴。
我们，有缘再见。 
*/
