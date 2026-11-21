#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
const int N=5005;
int n,m;
int p[N];

int dp[15][30];
int v[15],w[15];

const int mod=998244353;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res*=a;
            res%=mod;
        }
        a=a*a;
        a%=mod;
        b>>=1;
    }
    return res;
}
int C(int n,int m)
{
    int ans=1;
    for(int i=n;i>=(n-m+1);i--)
    {
        ans*=i;
    }
    for(int i=1;i<=m;i++)
    {
        ans/=i;
    }
    return ans;
}
bool cmp(pair<double,int> a,pair<double,int> b)
{
    if(a.first!=b.first) return a.first>b.first;
    else return a.second>b.second;
}

bool check(int mask)
{
    memset(dp,0,sizeof(dp));
    vector<pair<double,int>> s;
    for(int i=1;i<=n;i++)
    {
        if((mask>>(i-1))&1)
        {
            s.push_back(make_pair(p[i],p[i]));
            v[i]=1;
            w[i]=p[i];

        }
        else
        {
            s.push_back(make_pair(p[i]/2.0,p[i]));
            v[i]=2;
            w[i]=p[i];
// 

        }
        
    }
    sort(s.begin(),s.end(),cmp);

    int ans=0,cost=0,res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i].first!=s[i].second)
        {
            if(cost+2>m) continue;
            cost+=2;
            ans+=s[i].second;
        }
        else
        {
            if(cost+1>m) continue;
            cost+=1;
            ans+=s[i].second;

        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++) 
        {
            dp[i][j]=dp[i-1][j];
            if(j) 
            {
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        for(int j=v[i];j<=m;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
        }
    }
    res=dp[n][m];
    // cout<<ans<<" "<<res<<endl;
    return (ans==res);
}

signed main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        // sort(p+1,p+n+1);
        // int ans=0;
        // for(int i=2;i<=2;i++)
        // {
        //     if(i<=m)
        //     {
        //         for(int j=n;j>=1;j--)
        //         {
        //             int v=(p[j]+1)/2;
        //             int pos=upper_bound(p+1,p+n+1,v)-(p);
        //             cout<<p[j]<<' '<<v<<" "<<pos<<endl;
        //             if(n-pos+1>=(i+(m-i)/2+1))
        //             {
        //                 ans+=C(i+(m-i)/2,i);
        //                 cout<<i<<" "<<C(i+(m-i)/2,i)<<endl;
        //             }
        //         }
        //     }
        // }
        // cout<<ans<<endl;
        // check(5);
        
        if(c<=5)
        {
            int ans=0;
            for(int i=0;i<(1<<n);i++)
            {
                if(check(i))
                {
                    // cout<<i<<endl;
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<qpow(2,n)<<endl;
        }
    }
}