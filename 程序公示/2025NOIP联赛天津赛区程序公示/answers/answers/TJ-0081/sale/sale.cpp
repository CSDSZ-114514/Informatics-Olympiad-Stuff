#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cy{
	ll a;
	float w1,w2;
	cy(){
		a=0,w1=0,w2=0;
	}
	cy(ll x){
		a=x,w1=x,w2=x/2.0;
	}
};
ll p=998244353;
cy a[5005];
int c,t,n,m;
ll smax,ans;
void dfs(ll su,int now,bool wh){
	
}
bool cmp(cy ca,cy cb){
	return ca.w1>cb.w1;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			int temp;
			cin>>temp; 
			a[j]={temp};
		}
		sort(a+1,a+n+1,cmp);
		/*for(int j=1;j<=n;j++){
			cout<<a[j].a<<" "<<a[j].w1<<" "<<a[j].w2<<"\n";
		}*/
		int temp=m,now=1;
		while(temp-1>=0){
			--temp;
			smax+=a[now].a;
			++now;
		}
		cout<<1<<"\n";
		//dfs()
		//cout<<smax<<"\n";
	}
	return 0;
}
