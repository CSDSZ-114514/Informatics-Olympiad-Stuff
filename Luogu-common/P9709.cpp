#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
};
struct node1{
	long long x,y;
};
long long n,m;long long mp[150][150],f[150][150],cnt;
node ed[4000005];node1 pt[4000005];
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
queue<node1> q;long long dx[8]={2,2,-2,-2,1,1,-1,-1},dy[8]={1,-1,1,-1,2,-2,2,-2}; 
void bfs(int s){
	f[pt[s].x][pt[s].y]=1;
	q.push({pt[s].x,pt[s].y});
	while(!q.empty()){
		node1 u=q.front();
		q.pop();
		for(int i=0;i<=7;i++){
			int tx=u.x+dx[i];
			int ty=u.y+dy[i];
			if(tx>0&&ty>0&&tx<=m&&ty<=m &&f[tx][ty]==0){
				f[tx][ty]=f[u.x][u.y]+1;
				q.push({tx,ty});
				if(mp[tx][ty]){
					ed[++cnt]={s,mp[tx][ty],f[tx][ty]};
				}
			}
		}
	}
}
int karasu() {
	for(int i=1; i<=n; i++) {
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
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long a,b;
		cin>>a>>b;
		mp[a][b]=i;
		pt[i].x=a;pt[i].y=b;
	}
	for(int i=1;i<n;i++){
		memset(f,0,sizeof(f));
		bfs(i);
	}
	cout<<karasu();
}
