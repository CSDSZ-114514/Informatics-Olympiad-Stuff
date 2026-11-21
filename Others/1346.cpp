#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int baba[20005];
int zhaobaba(int x){
	if(baba[x]==x){
		return x;
	}else{
		return baba[x]=zhaobaba(baba[x]);
	}
}
int babazaiyiqi(int a,int b){
	baba[zhaobaba(a)]=zhaobaba(b);
	return 0;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		baba[i]=i;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		babazaiyiqi(a,b);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int c,d;
		cin>>c>>d;
		if(zhaobaba(c)==zhaobaba(d)){
			cout<<"Yes"<<'\n';
		}else{
			cout<<"No"<<'\n';
		}
	}
	
	return 0;
	
}
