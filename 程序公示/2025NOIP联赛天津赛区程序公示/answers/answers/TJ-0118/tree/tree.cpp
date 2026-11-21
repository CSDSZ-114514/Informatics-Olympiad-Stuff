#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge{
	int to,nxt;
}edge[8001];
int t,head[8001],ccnt[8001],cnt,ans,n,m,zhi[8001];
void add(int a,int b){
	edge[++cnt].to = b;
	edge[cnt].nxt = head[a];
	head[a] = cnt;
}
void dfs(int x){
	ccnt[zhi[x]]++;
	for (int i = head[x];i;i = edge[i].nxt){
		int j = edge[i].to;
		dfs(j);
	}
}
void fu(int a){
	if (a == n + 1){
		int cur = 0;
		for (int i = 1;i <= n;i++){
			for (int i = 0;i <= n;i++){
				ccnt[i] = 0;
			}
			dfs(i);
			for (int i = 0;i <= n;i++){
				if (ccnt[i] == 0){
					cur += i;
					break;
				}
			}
		}
		ans = max(ans,cur);
		return ;
	}
	for (int i = 0;i <= n;i++){
		zhi[a] = i;
		fu(a + 1);
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&t);
	while (t--){
		scanf("%lld%lld",&n,&m);
		for (int i = 2;i <= n;i++){
			int p;
			scanf("%lld",&p);
			add(p,i);
		}
		fu(1);
		printf("%lld\n",ans);
	}
	return 0;
}
