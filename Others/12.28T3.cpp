#include<bits/stdc++.h>
using namespace std;
long long n,k,d;
const long long N=1e7+5;
long long a[N],cost[N],psum[N],f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    //cout<<a[1];
    if(d==0){
        long long ans=0,cnt=0;
        for(int i=1;i<=n+1;i++){
            if(a[i]!=a[i-1]){
                //cout<<cnt<<endl;
                ans+=((k-(cnt%k))%k);
                cnt=0;
            }cnt++;
        }
        cout<<ans;
        return 0;
    }

    for(int i=1;i<=n;i++){
        cost[i]=max((a[i]-a[i-1]-1)/d,(long long)0);
    }
    for(int i=1;i<=n;i++){
        psum[i]=psum[i-1]+cost[i];
        f[i]=INT_MAX;
    }
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;i-j>=0;j++){
            long long pos=i-j;
            if(a[i]-a[pos+1]>k*d)break;
            long long add1=psum[i]-psum[pos+1];
            long long add2=(k-(i-pos+add1)%k)%k;
            f[i]=min(f[i],f[pos]+add1+add2);
        }
    }
    cout<<f[n];
    return 0;
}