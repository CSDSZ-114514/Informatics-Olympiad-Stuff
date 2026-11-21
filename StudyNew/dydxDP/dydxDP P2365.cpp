#include<bits/stdc++.h>
using namespace std;
long long n,s;
long long t[1000005],f[1000005],q[1000005];
long long dp[1000005],qzh[1000005],qzh2[1000005];
double slope(long long x,long long y){
    return 1.00*(dp[x]-dp[y])/(f[x]-f[y]);
    return 0;
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>f[i];
        f[i]+=f[i-1];
        t[i]+=t[i-1];
    }
    long long h=1,v=0;
    for(int i=1;i<=n;i++){
        double k=t[i]+s
        ;
        while(v>h&&slope(i-1,q[v])<=slope(q[v],q[v-1])){
            v--
            ;
        }
        q[++v]=i-1
        ;
        while(v>h&&slope(q[h+1],q[h])<=k){
            h++
            ;
        }
        dp[i]= dp[q[h]]+t[i]*(f[i]-f[q[h]])+s*(f[n]-f[q[h]])
        ;
    }
    cout<<dp[n]
    ;
    return 0
    ;
}