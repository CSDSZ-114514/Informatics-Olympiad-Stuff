#include<bits/stdc++.h>
using namespace std;
int t,n,m,fa[10005],cnt[10005];
struct node{
	int f,s;
};
vector<node> e[10005];
queue<int> q;
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		int p;
		node fs;
		for(int i=2;i<=n;i++){
			cin>>p;
			fs.f=p;
			fs.s=i;
			e[p].push_back(fs);
			fa[p]=i;
		} 
		if(m==2) cout<<n*m-1;
		else cout<<n+m;
	}
	return 0;
}
