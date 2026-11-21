#include<bits/stdc++.h>
using namespace std;
long long n,wkk,cnt,fa[10005],dps[10005];
struct node{
	long long u,v,w,wk;
};
node ed[10005];
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
int karasu(int a) {
	for(int i=1; i<=n; i++) {
		fa[i] = i;
	}

	long long sum=0;long long qnt=0;
	for(int i=1; i<=cnt; i++) { 
		int x = find(ed[i].u); 
		int y = find(ed[i].v);
		if(x != y&&ed[i].wk<=a) { 
			sum+=ed[i].w;
			qnt++;
			if(qnt==n-1){
				break;
			}
			fa[x] = y; 
		}
	}
	return qnt==n-1?sum:-1;
}
int main(){
	cin>>n>>wkk;
	while(wkk--){
		long long a,b,c;
		cin>>a>>b>>c;
		ed[++cnt].u=a;ed[cnt].v=b;ed[cnt].w=c;ed[cnt].wk=cnt;
		//cout<<"dps[i]"<<1<<endl;
	}
	sort(ed+1,ed+1+cnt,cmp);
	for(int i=cnt;i>=1;i--){
		
		dps[i]=karasu(i);
		
	}
	for(int i=1;i<=cnt;i++){
		cout<<dps[i]<<endl;
	}
	
	
	return 0;
}
