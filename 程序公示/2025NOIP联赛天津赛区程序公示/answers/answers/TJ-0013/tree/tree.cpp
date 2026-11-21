#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[1000],g[1005],a[1000];
int n,m,ans;
vector<int > e[1000];

int dfs(int x,int fa){
	int cnt = 0;
	for (int t:e[x]){
		if (t == fa)continue;
		cnt = cnt | dfs(t,x);
	} 
	cnt = cnt | (1<<a[x]);
	int cntt = cnt,idx = 0;
	//cout<<cnt<<endl;
	while (1){
		if (cntt % 2 == 0){
			g[x] = idx;
			break;
		}
		cntt>>=1;
		idx++;
	}
	
	return cnt;
	
}

void dg(int x){
	if (x == n+1){
	//	cout<<"diguijieshu"<<endl;
		dfs(1,0);
		int sum = 0;
		for (int i = 1;i<=n;i++)sum += g[i];
		ans = max(ans,sum);
		return ;
	}
	for (int i = 0;i<=n;i++){
		a[x] = i;
		dg(x+1); 
	}
	
}

signed main(){
	freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	
	int T;
	cin>>T; 
	
	while (T--){
		cin>>n>>m;
		
		for(int i=1;i<=n;i++)e[i].clear();
		for (int i = 2;i<=n;i++){
			cin>>f[i];
			e[f[i]].push_back(i);
		}
		dg(1);
		cout<<ans<<endl;
	}
	
	return 0;
}
