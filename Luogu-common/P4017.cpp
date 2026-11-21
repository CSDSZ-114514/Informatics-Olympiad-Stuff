#include<bits/stdc++.h>
using namespace std;
long long n,m,rd[10005],cd[10005],f[10005];vector<int> ed[10005];queue<int> q;
void tp(){
	for(int i=1;i<=n;i++){
		if(rd[i]==0){
			q.push(i);
			f[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int t:ed[u]){
			rd[t]--;
			f[t]=((f[t]+f[u])% 80112002) ;
			if(rd[t]==0){
				q.push(t);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a=0,b=0;
		cin>>a>>b;
		ed[a].push_back(b);
		cd[a]++;rd[b]++;
	}
	tp();int sum=0;
	for(int i=1;i<=n;i++){
		if(cd[i]==0){
			sum+=f[i];
		}
	}
	cout<<sum%80112002;
	return 0;
}
