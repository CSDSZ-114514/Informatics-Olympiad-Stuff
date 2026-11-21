#include <bits/stdc++.h>
using namespace std;
long long n,m,mok[10005],trx1[1005],try1[1005];long long cnt=0;
struct node{
	long long u,v,w;
};
long long fa[1000005];node ed[1000005];
int find(int x) {
	if(x == fa[x]) {
		return x;
	} else {
		return fa[x] = find(fa[x]);
	}
}
bool cmp(node ax,node ay){
	return ax.w<ay.w;
}
int karasu() {
	for(int i=1; i<=n; i++) {
		fa[i] = i;
	}
	sort(ed+1,ed+cnt+1,cmp);
	long long mx=0;
	for(int i=1; i<=cnt; i++) { 
		int x = find(ed[i].u); 
		int y = find(ed[i].v);
		if(x != y) { 
			mx =max(mx,ed[i].w) ; 
			fa[x] = y; 
		}
	}
	return mx;
}

int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>mok[i];
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>trx1[i]>>try1[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ed[++cnt].u=i;
			ed[cnt].v=j;
			ed[cnt].w=ceil(sqrt((trx1[i]-trx1[j])*(trx1[i]-trx1[j])+(try1[i]-try1[j])*(try1[i]-try1[j])));
		}
	}long long ans=0,pq=karasu();
	for(int i=1;i<=n;i++){
		if(mok[i]>=pq){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
