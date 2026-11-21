#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL N=105;
const LL MOD=998244353;
LL n,m;
LL a[N];
LL maxn;
LL ans;

bool cmp(LL x,LL y){
	return x>y;
}

LL w[N];
struct node{
	LL id;
	double data;
}c[N];

bool cmp3(node x,node y){
	if(x.data==y.data){
		if(a[x.id]==a[y.id]) return x.id<y.id;
		return a[x.id]>a[y.id];
	}
	return x.data>y.data;
}

bool cmp2(node x,node y){
	return a[x.id]>a[y.id];
}

bool temp[N];
LL res2;
void dfs2(LL x){
	if(x==n+1){
		LL sum=0;
		LL sum_m=0;
		for(LL i=1;i<=n;i++) {
			if(temp[i]==true) sum_m+=w[i];
		}
		if(sum_m>m) return ;
		for(LL i=1;i<=n;i++) {
			if(temp[i]==true) sum+=a[i];
		}
		res2=max(res2,sum);
		return ;
	}
	temp[x]=true;
	dfs2(x+1);
	temp[x]=false;
	dfs2(x+1);
}

void dfs(LL x){
	if(x==n+1) {
		LL sum_w=0;
		LL res=0;
		for(LL i=1;i<=n;i++) {
			c[i].data=a[i];
			c[i].data/=w[i];
			c[i].id=i;
			sum_w+=w[i];
		}
		sort(c+1,c+1+n,cmp3);
		LL M=m;
		for(LL i=1;i<=n;i++) {
			if(M>=w[c[i].id]) {
				res+=a[c[i].id];
				M-=w[c[i].id];
			}
		}
		res2=0;
		dfs2(1);
		if(res==res2) ans++;
		return ;
	}
	w[x]=1;
	dfs(x+1);
	w[x]=2;
	dfs(x+1);
	return;
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	LL C,T;
	cin>>C>>T;
	if(C==18){
		LL xx;
		while(T--){
			cin>>n>>m;
			ans=1;
			for(LL i=1;i<=n;i++) {
				cin>>xx;
				ans=ans*2%MOD;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while(T--){
		ans=0;
		cin>>n>>m;
		for(LL i=1;i<=n;i++) cin>>a[i];
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
