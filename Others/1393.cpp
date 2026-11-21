#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct Node{
	long long p,u,v,w;
}nd[100005];
long long fa[100005];long long sum;

long long findroot(long long x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=findroot(fa[x]);
}
void heb(long long a,long long b){
	fa[findroot(a)]=findroot(b);
}
bool cmp(Node x,Node y){
	return y.w>x.w;
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(nd[i].p==1){
			heb(nd[i].u,nd[i].v);
			sum+=nd[i].w;
		}
	}
}
void krs(){
	init();
	sort(nd+1,nd+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(nd[i].p==2&&findroot(nd[i].u)!=findroot(nd[i].v)){
			sum+=nd[i].w;
			heb(nd[i].u,nd[i].v);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>nd[i].p>>nd[i].u>>nd[i].v>>nd[i].w;
	}
	krs();
	cout<<sum;
	return 0;
}
