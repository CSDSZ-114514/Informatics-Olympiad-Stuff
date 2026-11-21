#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
struct abc{
	int v,w;
	double x;
}a[5005];
const long long C=998244353;
long long abc(long long a,long long b){
	a%=C;
	long long res=1;
	while (b){
		if (b&1){
			res*=a;
			res%=C;
		}a*=a;
		a%=C;
		b>>=1;
	}return res;
}
void dfs(int x){
	if (x==n){
		
	}else{
		for (int i=1;i<=2;i++){
			a[i].w=i;
			a[i].x=a[i].v*1.0/a[i].w;
			dfs(x+1);
		}
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>m;
		bool bj=0;
		for (int i=0;i<n;i++){
			cin>>a[i].v;
			if (i>0 && a[i].v!=a[i-1].v){
				bj=1;
			}
		}cout<<abc(2,n)<<endl;
	}
	return 0;
} 
