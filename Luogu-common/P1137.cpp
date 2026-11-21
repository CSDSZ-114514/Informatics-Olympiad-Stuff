#include<bits/stdc++.h>
using namespace std;
vector<int> ed[100005];
long long n,m,rd[100005],ct[100005],cnt,f[100005];
queue<int> q;
void tp(){
	for(int i=1;i<=n;i++){
		if(rd[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int t:ed[u]){
			f[t]=max(f[t],f[u]+1);
			rd[t]--; 
			if(rd[t] == 0){
				q.push(t);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		long long a,b;
		cin>>a>>b;
		ed[a].push_back(b);
		rd[b]++;
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
	tp();
	for(int i=1;i<=n;i++){
		cout<<f[i]<<endl;
	}
	return 0;
}
