#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=8010;
int t,n,m,p[N],h[N],fh[N],s[N],ans[N],anss; // s后缀和,fh到最低叶子结点距离 
vector<int> v[N];

void init(int x){
	int sz=v[x].size();
	if(!s[x]) s[x]=1;
	for(int i=0;i<sz;i++){
		h[v[x][i]]=h[x]+1;
		init(v[x][i]);
		s[x]+=s[v[x][i]];
		fh[x]=max(fh[v[x][i]]+1,fh[x]);
	}
}

void dfs(int x){
	int sz=v[x].size();
	int son=0;
	for(int i=0;i<sz;i++){
		if(fh[v[x][i]]>fh[son]){
			son=v[x][i];
		}
		else if(fh[v[x][i]]==fh[son]){
			if(s[v[x][i]]>s[son]){ // 这里有错误 
				son=v[x][i];
			}
		}
	}
	for(int i=0;i<sz;i++){
		if(v[x][i]!=son){
			ans[v[x][i]]=ans[x];
		}
		else{
			ans[son]=ans[x]+1;
		}
		dfs(v[x][i]);
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) p[i]=h[i]=fh[i]=s[i]=ans[i]=0;
		for(int i=2;i<=n;i++){
			cin >> p[i];
			v[p[i]].push_back(i);
		}
		init(1);
		ans[1]=1; 
		dfs(1);
		anss=0;
		for(int i=1;i<=n;i++) anss+=ans[i];
		cout << anss << '\n';
	}
	
	return 0;
} 
