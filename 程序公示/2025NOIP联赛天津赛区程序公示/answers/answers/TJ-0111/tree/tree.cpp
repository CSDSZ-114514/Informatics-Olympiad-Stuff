#include<bits/stdc++.h>
using namespace std;
vector<int>v[8005];
int n,m,a[8005],cnt[8005][8005],ANS=0,ans=0;
void dfs2(int x){
	for(int i=0;i<v[x].size();i++){
		dfs2(v[x].at(i));
		for(int j=0;j<n;j++){
			cnt[x][j]+=cnt[v[x].at(i)][j];
		}
	}
	cnt[x][a[x]]++;
	int mex=0;
	while(cnt[x][mex]){
		mex++;
	}
	ans+=mex;
}
void dfs1(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
				cnt[i][j]=0;
			}
		}
		ans=0;
		dfs2(1);
		ANS=max(ANS,ans);
		return;
	}
	for(int i=0;i<n;i++){
		a[x]=i;
		dfs1(x+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			v[x].push_back(i);
		}
		dfs1(1);
		cout<<ANS<<"\n";
		for(int i=1;i<=n;i++){
			v[i].clear();
			a[i]=0;
		}
	}
	return 0;
} 
