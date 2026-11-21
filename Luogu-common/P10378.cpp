#include<bits/stdc++.h>
using namespace std;
long long n,m;vector<int> ed[100005];
long long f[100005],num1,num0,nummx=0,nummn=0;
void dfs(int up){
	for(int v:ed[up]){
		if(f[v]==-1){
			if(f[up]==1){
				f[v]=0;
				num0++;
			}else{
				f[v]=1;
				num1++;
			}
			dfs(v);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++){
		num0=0;num1=0;
		if(f[i]==-1){
			num1+=1;f[i]=1;
			dfs(i);
			nummx+=max(num0,num1);
			nummn+=min(num0,num1);
		}
	}
	cout<<nummn<<" "<<nummx;
	return 0;
}
