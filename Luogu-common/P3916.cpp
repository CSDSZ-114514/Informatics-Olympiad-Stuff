#include<bits/stdc++.h>
using namespace std;
queue<int> q;vector<int> a[100005];
int n,m,f[100005];
int u,v;
void bfs(){
	while(!q.empty()){
		int uc=q.front();
		q.pop();
		for(int t:a[uc]){
			if(f[t]==-1){
				q.push(t);
				f[t]=f[uc];
			}
		}
	}
}
int main(){
	cin>>n>>m;
	//cout<<n<<m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		a[v].push_back(u);
	}
	memset(f,-1,sizeof(f));
	//cout<<f[1];
	for(int i=n;i>=1;i--){
		if(f[i]==-1){
			f[i]=i;
			q.push(i);
			bfs();
		}
	}
	for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
}
