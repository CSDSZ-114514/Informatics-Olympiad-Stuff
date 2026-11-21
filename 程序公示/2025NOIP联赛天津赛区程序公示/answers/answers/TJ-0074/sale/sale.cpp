#include<bits/stdc++.h>
using namespace std;

long long pow2[10000];
int a[10000];
struct obj{
	int x;
	int y;
	int xing;
};
bool cmp(obj o1,obj o2){
	return o1.xing>o2.xing;
}
obj o[10000];int n,m,ans=0;
int dfs(int step){
	if(step<n){
		o[step+1].y=1;
		dfs(step+1);
		o[step+1].y=2;
		dfs(step+1);
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			o[i].x=a[i];
			o[i].xing=o[i].x*2/o[i].y;
		}sort(o+1,o+n+1,cmp);
		int b=m,i=0,val=0;
		while(b>0&&b>o[i+1].y&&i<=n){
			val+=o[i+1].x;
			b-=o[i+1].y;
			i++;
		}
		if(i==n||b==0){
			ans++;
		}
		return 0;
	}
}
void solve(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flg=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1])flg=0;
	}
	if(flg){
		cout<<pow2[n]<<"\n";
	}
	else{
		dfs(0);
		
		
		cout<<ans<<"\n";ans=0;
	}
	return;
}
int main(){
	pow2[0]=1;
	for(int i=1;i<=5500;i++){
		pow2[i]=pow2[i-1]*2;
		pow2[i]%=998244353;
	}
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,T;
	cin>>c>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}
