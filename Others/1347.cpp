#include<bits/stdc++.h>
using namespace std;
long long n,m,fa[60005];
int findfa(int x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=findfa(fa[x]);
	}
}
void bingfa(int a,int b){
	fa[findfa(a)]=findfa(b);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int a,b;char c;
		cin>>a>>b>>c;
		if(c=='D'){
			if(findfa((a-1)*n+b)==findfa((a)*n+b)){
				cout<<i;
				return 0;
			}
			bingfa((a-1)*n+b,(a)*n+b);
		}
		if(c=='R'){
			if(findfa((a-1)*n+b)==findfa((a-1)*n+b+1)){
				cout<<i;
				return 0;
			}
			bingfa((a-1)*n+b,(a-1)*n+b+1);
		}
		
	}
	cout<<"draw";
	
	
	
	return 0;
	
}
