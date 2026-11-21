#include<bits/stdc++.h>
using namespace std;
long long n,k;
struct Node{
	long long u,v,w;
}nd[10005];
long long fa[10005];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
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
int krs(){
	long long sum=0;
	init();
	sort(nd,nd+1+k,cmp);
	for(int i=1;i<=n;i++){
		if(findroot(nd[i].u)!=findroot(nd[i].v)){
			heb(nd[i].u,nd[i].v);
			sum+=nd[i].w;
		}
	}
	return sum;
}
int main(){
	cin>>n>>k;long long sum=0;
	for(int i=1;i<=k;i++){
		int a,b,c;
		cin>>a>>b>>c;
		nd[i].u=a;nd[i].v=b;nd[i].w=c;
		sum+=c;
	}
	cout<<sum-krs();
}
