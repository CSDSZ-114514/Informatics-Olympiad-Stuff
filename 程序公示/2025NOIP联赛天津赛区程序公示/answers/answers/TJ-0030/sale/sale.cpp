#include<bits/stdc++.h>
using namespace std;
struct node{
	double v,pr,ind;
}a[11];
int cmp(node p,node q){
	return p.v/p.pr>q.v/q.pr;
	return p.v>q.v;
	return p.ind<q.ind;
}
int c,t,n,m,v[11],dp[11][21],pr[11];
void solve(int x){
	if(x==n){
		for(int i=1;i<=n;i++){
			for(int j=pr[i];j<=m;j++)dp[i][j]=max(dp[i][j],dp[i-1][j-pr[i]]+v[i]);
		}
		for(int i=1;i<=n;i++)a[i]={v[i],pr[i],i};
		sort(a+1,a+n+1,cmp);
	}
	pr[x]=1;
	solve(x+1);
	pr[x]=2;
	solve(x+2);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>v[i];
		solve(0);
	}
	return 0;
} 
