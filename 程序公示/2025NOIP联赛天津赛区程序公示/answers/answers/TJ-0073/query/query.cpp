#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[8005],fa[8005],er[8005][805],du[8005],cnt[8005];
int head[20005],ver[20005],Next[20005],tot;
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
int vis[8005];
void dfs(int s){
	
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		tot=0;
		memset(head,-1,sizeof(head));
		scanf("%d%d",&n,&m);
		fa[1]=-1;
		for(int i=2;i<=n;i++){
			scanf("%d",&a[i]);
			add(a[i],i);
			add(i,a[i]);
			fa[i]=a[i];
			du[i]++;
			du[a[i]]++;
		}
	}
	return 0;
} 
