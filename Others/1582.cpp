#include<bits/stdc++.h>
using namespace std;
int n,rd[10005],hp[10005],f[10005][5];vector<int> ed[10005];
void dfs(int u){
	f[u][1]=hp[u];
	for(int t:ed[u]){
		dfs(t);
		f[u][1]+=f[t][0];
		f[u][0]+=max(f[t][0],f[t][1]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>hp[i];
	}
	while(true){
		int a=0,b=0;
		cin>>a>>b;
		if(a==0&&b==0){
			break;
		}else{
			ed[b].push_back(a);
			rd[a]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(rd[i]==0){
			dfs(i);
			cout<<max(f[i][0],f[i][1]);
			return 0;
		}
	}
	return 0;
}
