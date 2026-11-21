#include<bits/stdc++.h>
using namespace std;
long long n,m,ed[1005][1005];
queue<int> q;long long d[100005],pre[100005];bool vis[500005];
void spfa(long long s){
	q.push(s);
	for(int i=1;i<=n;i++){
		d[i]=1e9;
	}
	vis[s]=1;
	d[s]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		vis[t]=0;
		for(int i=1;i<=n;i++){
			if(ed[t][i]!=-1){
				if(d[i]>d[t]+ed[t][i]){
					d[i]=d[t]+ed[t][i];
					pre[i]=t;
					if(vis[i]==0){
						q.push(i);
						vis[i]=1;
					}
				}
			}
		}
	}
}
void spfa1(long long s){
	q.push(s);
	for(int i=1;i<=n;i++){
		d[i]=1e9;
	}
	vis[s]=1;
	d[s]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		vis[t]=0;
		for(int i=1;i<=n;i++){
			if(ed[t][i]!=-1){
				if(d[i]>d[t]+ed[t][i]){
					d[i]=d[t]+ed[t][i];
					//pre[i]=t;
					if(vis[i]==0){
						q.push(i);
						vis[i]=1;
					}
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;memset(ed,-1,sizeof(ed));
	for(int i=1;i<=m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
//		ed[a].push_back({b,c});
//		ed[b].push_back({a,c});
		ed[a][b]=c;
		ed[b][a]=c;
	}
	spfa(1);
	pre[1]=0;
	long long dp=d[n],l=0;
	long long t=n;
	while(t!=0){
		ed[t][pre[t]]*=2;
		ed[pre[t]][t]*=2;
		spfa1(1);
		l=max(l,d[n]);
		ed[t][pre[t]]/=2;
		ed[pre[t]][t]/=2;
		t=pre[t];
	}
	cout<<l-dp;
	return 0;
}
