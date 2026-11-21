#include<bits/stdc++.h>
using namespace std;
long long n,cnt,fa[100005],sum;
struct Node{
	long long u,v,w;
}nd[100005];
void init(){
	for(int i=1;i<=100000;i++){
		fa[i]=i;
	}
}
int findroot(int a){
	if(fa[a]==a){
		return a;
	}else{
		return fa[a]=findroot(fa[a]);
	}
}
void heb(int a,int b){
	fa[findroot(a)]=fa[b];
}
bool cmp(Node x,Node y){
	return y.w>x.w;
}
void djgun(){
	
	
	sort(nd+1,nd+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(findroot(nd[i].u)!=findroot(nd[i].v)){
			sum+=nd[i].w;
			heb(nd[i].u,nd[i].v);
		}
	}
}
int main(){
	cin>>n;init();
	for(int i=1;i<=n;i++){
		
		nd[++cnt].u=100000;nd[cnt].v=i;
		cin>>nd[cnt].w;
	}
	for(long i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			nd[++cnt].u=i;nd[cnt].v=j;
			cin>>nd[cnt].w;
		}
	}
	djgun();
	cout<<sum;
	return 0;
}
