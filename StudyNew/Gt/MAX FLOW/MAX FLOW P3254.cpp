#include<bits/stdc++.h>
using namespace std;
int n,m,x,s,t,ans=0,cnt=0;
struct node{
	int u,v,w; 
};
vector<node> e;
vector<int> h[1005];
int d[1005];
bool bfs(){
	memset(d,0,sizeof(d));
	d[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==t){
			return true;
		}
		for(int i:h[u]){
			int v=e[i].v;
			if(d[v]==0&&e[i].w>0){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return false;
}
int dfs(int u,int mf){
	if(u==t){
		return mf;
	}
	int sum=0;
	for(int i:h[u]){
		int v=e[i].v;
		if(d[v]==d[u]+1&&e[i].w>0){
			int f=dfs(v,min(mf,e[i].w));
			sum+=f;
			mf-=f;
			e[i].w-=f;
			e[i^1].w+=f;
			if(mf==0){
				break;
			}
		}
	}
	return sum;
}
int main(){
	cin>>m>>n;
	s=0,t=n+m+1;
	for(int i=1;i<=m;i++){
		cin>>x;
		e.push_back({s,i,x});
		h[s].push_back(e.size()-1);
		e.push_back({i,s,0});
		h[i].push_back(e.size()-1);
		cnt+=x;
	}
	for(int i=m+1;i<=m+n;i++){
		cin>>x;
		e.push_back({i,t,x});
		h[i].push_back(e.size()-1);
		e.push_back({t,i,0});
		h[t].push_back(e.size()-1);
	}
	for(int i=1;i<=m;i++){
		for(int j=m+1;j<=m+n;j++){
			e.push_back({i,j,1});
			h[i].push_back(e.size()-1);
			e.push_back({j,i,0});
			h[j].push_back(e.size()-1);
		}
	}
	while(bfs()){
		ans+=dfs(s,1e9);
	}
	if(ans!=cnt){
		cout<<0;
	}else{
		cout<<1<<endl;
			for(int j=1;j<=m;j++){
				for(int i:h[j]){
					if(e[i].w==0 && e[i].v!=0){
						cout<<e[i].v-m<<" ";
					}
				}	
				cout<<endl;
			}
	}
}