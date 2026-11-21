#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
#include<set>
template<typename T> bool tense(T &a,const T &b){return b<a?(a=b,true):false;}
template<typename T> bool relax(T &a,const T &b){return b>a?(a=b,true):false;}

int n,m;

namespace Force{
	const int N = 8010,M = 2*N;
	int h[N],e[M],ne[M],idx;
	int fa[N],depth[N];
	int w[N],mex[N];
	int root = 1;
	
	void add(int u,int v){
		e[++idx] = v,ne[idx] = h[u],h[u] = idx;
	}
	int get(int u){
		int s = (1<<w[u]);
		for(int i=h[u];i;i=ne[i]){
			int v = e[i];
			if(v==fa[u]) continue;
			s|=get(v);
		}
		for(int i=0;i<=n;i++) if(~s>>i&1){
			mex[u] = i;
			break;
		}
		return s;
	}
	int dfs(int i){
		if(i>n){
			get(root);
			int res = 0;
			for(int i=1;i<=n;i++) res+=mex[i];
			return res;
		}
		int res = 0;
		for(int x=0;x<=n;x++){
			w[i] = x;
			relax(res,dfs(i+1));
		}
		return res;
	}
	void solve(){
		for(int i=2;i<=n;i++) scanf("%d",&fa[i]),add(i,fa[i]),add(fa[i],i);
		printf("%d\n",dfs(1));
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	Force::solve();
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}

 
