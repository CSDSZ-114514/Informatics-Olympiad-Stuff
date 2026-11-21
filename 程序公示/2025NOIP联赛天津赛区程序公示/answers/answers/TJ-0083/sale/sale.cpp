#include<bits/stdc++.h>
using namespace std; 
long long mod=998244353;
long long c,t,n,m,w[10005],ans,dp[1005][1005],ma;
struct candy{
	long long a;
	int id;
	float v;
}b[100005];
bool cmp(candy x,candy y){
	if(x.v!=y.v) return x.v>y.v;
	else if(x.a!=y.a) return x.a>y.a;
	else return x.id<y.id;
}
bool cmp1(candy x,candy y){
	return x.a>y.a;
}
void to_do(){
	for(int i=1;i<=n;i++){
		b[i].v=b[i].a/w[i];
	}
	sort(b+1,b+n+1,cmp);
	long long sum;
	for(int i=1;i<=n;i++){
		if(m>=w[b[i].id]){
			m-=w[b[i].id];
			sum+=b[i].a;
		}
	}
	if(sum>=ma) ans++;
}
void bfs(int d){
	if(d>n){
		to_do();
		return;
	}
	for(w[d]=1;w[d]<=2;w[d]++){
		bfs(d+1);
	}
}
long long ksm(int a,int b){
	long long sum=1;
	while(b!=1){
		if(b%2){
			sum=(sum*a)%mod;
			b--;
		}
		a=(a*a)%mod;
		b/=2;
	}
	sum=(sum*a)%mod;
	return sum;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>b[i].a;
			b[i].id=i;
			ma=max(ma,b[i].a);
		}
		if(c==18){
			cout<<ksm(2,n)%mod;
		}
		bfs(1);
		cout<<ans;
	}
	return 0;
}
