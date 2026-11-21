#include<bits/stdc++.h>
using namespace std;
long long n,s;
long long t[1000005],f[1000005],q[1000005];
long long dp[1000005];
long long a=1,b=0;
double dydx(long long a,long long b){
    return 1.0*(dp[b]-dp[a])/(f[b]-f[a]);
}
long long erf(long long k,long long l,long long r){
    if(l==r)return l;
    while (l<r){
        long long mid=(l+r)>>1;
        if(dydx(q[mid],q[mid+1])<=k){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return r;
    
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>f[i];
        f[i]+=f[i-1];
        t[i]+=t[i-1];
    }
    
    for(int i=1;i<=n;i++){
        double k=t[i]+s;
        while(a<b&&dydx(i-1,q[b])<=dydx(q[b],q[b-1])){
            b--;
        }
        q[++b]=i-1;
        long long j=erf(k,a,b);
        dp[i]= dp[q[j]]+t[i]*(f[i]-f[q[j]])+s*(f[n]-f[q[j]]);
        
    }
    cout<<dp[n];
}