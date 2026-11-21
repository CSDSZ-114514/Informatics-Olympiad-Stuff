#include<bits/stdc++.h>
using namespace std;
long long d,n,m,t;
long long a[10005],sum[10005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>d>>n>>m>>t;
    for(int i=0;i<n;i++)cin>>a[i],a[i]%=d;
    long long tt=n/(__gcd(n,(m-1)%n));
    for(int i=0;i<tt;i++){
        for(int j=0;j<m;j++){
            sum[i]=(sum[i]+a[((i*(m-1)%n)%n+j-1+n)%n])%d;
        }
    }
    long long cnt=0;
    for(int i=0;i<tt;i++)cnt=(cnt+sum[i])%d;
    long long ans=(t/m/tt%d)*cnt%d;
    for(int i=0;i<t/m%tt;i++){
        ans=(ans+sum[i])%d;
    }
    if(t%m>0){
        for(int i=0;i<t%m;i++){
            ans=(ans+a[((t/m%n)*(m-1)%n+i-1+n)%n])%d;
        }
    }
    cout<<ans;
    return 0;
}