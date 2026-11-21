#include<bits/stdc++.h>
using namespace std;
struct node{
	int fa,num,cnt;
	vector<int>sn;
}a[8001];
int t,n,m,f,ans;
void dfs(int ind){
	if(a[ind].cnt==0)return;
	int maxx=0,ix=0;
	for(auto ed:a[ind].sn){
		dfs(ed);
		if(a[ed].cnt==0){
			a[ed].num=ix;
			ix++;
		}
		maxx=max(maxx,a[ed].num);
	}
	a[ind].num=maxx+1;
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			a[i].fa=0;
			a[i].num=0;
			a[i].cnt=0;
			a[i].sn.clear();
		}
		ans=0;
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			cin>>f;
			a[f].cnt++;
			a[f].sn.push_back(i);
			a[i].fa=f;
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			if(a[i].cnt==0){
				if(a[i].num==0)ans++;
			}else ans+=a[i].num+1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
