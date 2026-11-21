#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[100005],b[100005];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("genshin.in","r",stdin);
    freopen("genshin.out","w",stdout);
    cin>>n>>m>>k;
    long long ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=n;i++)ans+=a[i];
    for(int i=1;i<=m;i++)ans+=b[i];
    sort(a+1,a+1+n,cmp);
    //cout<<a[1];
    long long cnt=0;
    for(int i=1;i<=min(n,m);i++){
        if(a[i]>k){
            ans+=a[i];
            cnt++;
        }
    }
    ans=ans+k*(min(n,m)-cnt);
    cout<<ans;
}