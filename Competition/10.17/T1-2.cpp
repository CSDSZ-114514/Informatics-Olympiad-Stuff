#include<bits/stdc++.h>
using namespace std;
long long n;
long long w[100005],d[100005];
long long sumw[100005],sumx[100005],x[100005],dp[100005],q[100005],a,b; 
long long ans=1e18;
long double dydx(int u,int v){
    return 1.0L*(dp[v]-dp[u])/(sumw[v]-sumw[u]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i]>>d[i];
    for(int i=1;i<=n;i++)x[i+1]=x[i]+d[i];
    for(int i=1;i<=n;i++){
        sumw[i]=sumw[i-1]+w[i];
        sumx[i]=sumx[i-1]+w[i]*x[i];
        dp[i]=sumw[i]*x[i];
    }
    a=0;b=-1;
    q[++b]=1;   
    for(int k=2;k<=n;k++){
        while(a<b&&dydx(q[a],q[a+1])<=x[k]){
            a++;
        }
        int j=q[a];
        long long bj=dp[j]-sumw[j]*x[k];
        long long c=x[k]*sumw[k]-sumx[k]+x[n+1]*(sumw[n]-sumw[k])-(sumx[n]-sumx[k]);
        ans=min(ans,c+bj);
        while(a<b&&dydx(k,q[b])<=dydx(q[b],q[b-1])){
            b--;
        }
        q[++b]=k;
    }

    cout<<ans;
    return 0;
}
