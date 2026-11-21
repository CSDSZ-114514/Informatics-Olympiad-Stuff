#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
};
long long b,a,cnt;
node ed[250005];
long long fa[1000005];
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
	for(int i=1; i<=b; i++) {
		fa[i] = i;
	}
	sort(ed+1,ed+cnt+1,cmp);
	long long sum=0;
	for(int i=1; i<=cnt; i++) { 
		int x = find(ed[i].u); 
		int y = find(ed[i].v);
		if(x != y) { 
			sum+=ed[i].w;
			fa[x] = y; 
		}
	}
	return sum;
}
int main(){
	cin>>a>>b;
	for(int i=1;i<=b;i++){
		for(int j=1;j<=b;j++){
			long long z;
			cin>>z;
			if(z!=0||i==j){
				ed[++cnt].u=i;ed[cnt].v=j;ed[cnt].w=min(a,z);
			}else{
				ed[++cnt].u=i;ed[cnt].v=j;ed[cnt].w=a;
			}

		}
	}
	cout<<karasu()+a;
	
	return 0;
}
