#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
int n,a[N+5],b[N+5];
ll m;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int mn=1;
    for (int i=1;i<=n;i++){
        if (a[i]+b[i]<a[mn]+b[mn])mn=i;
        else if (a[i]+b[i]==a[mn]+b[mn]&&a[i]<a[mn])mn=i;
    }
    ll t=m/(a[mn]+b[mn]);
    int ok=0;
    ll x=m-t*(a[mn]+b[mn]);
    if (x>a[mn])ok=1,x-=a[mn];
    ll ans=t*2+ok;
    int z=a[mn];
    a[mn]=2e9;
    sort(a+1,a+n+1);
    for (int i=1;i<n;i++){
        if (x>=a[i])ans=max(ans,t*2+ok+i),x-=a[i];
        else{
            if (ok==1){ok=0,x+=z;}
            if (x>=a[i])ans=max(ans,t*2+ok+i),x-=a[i];
            else{
                ll p=(a[i]-x-1)/(z+b[mn])+1;
                if (t<p)break;
                t-=p;
                x+=(z+b[mn])*p;
                x-=a[i];
                if (x>=z)x-=z,ok=1;
                ans=max(ans,t*2+ok+i);
            }

        }
    }
    cout<<ans<<"\n";
}
