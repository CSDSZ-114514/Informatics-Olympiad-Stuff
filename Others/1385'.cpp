#include<bits/stdc++.h>
using namespace std;
long long n,m,fa[100005];
void init(){
	for(int i=1;i<=2*n;i++){
		fa[i]=i;
	}
}
long long find(long long x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
void toge(long long x,long long y){
	fa[find(x)]=find(y);
}
int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		long long p,x,y;
		cin>>p>>x>>y;
		if(p==0){
			toge(x,y);
		}else{
			toge(n+x,y);
			toge(n+y,x);
		}
	}int cnt=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i){
			cnt++;
		}
	}
	cout<<cnt;
}

