#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<string>
#include<cmath>
#include<set>
const int N=8005,M=16005;
int T,n,m;
struct G{
	int head[N],next[M],to[M];
	int len=0;
	void init(){
		len=0;
		for(int i=1;i<=n;i++) head[i]=0;
	}
	void insert(int x,int y){
		to[++len]=y;
		next[len]=head[x];
		head[x]=len;
	}
}g;
int par[N];
int rd[N];
namespace Force{
	int a[N];
	int q[N];
	std::set<int> bfs(int rt){
		std::set<int> s;
		int l=1,r=0;
		q[++r]=rt;
		while(l<=r){
			int x=q[l++];
			s.insert(a[x]);
			for(int i=g.head[x];i;i=g.next[i]){
				int y=g.to[i];
				if(par[x]!=y){
					q[++r]=y;
				}
			}
		}
		return s;
	}
	long long ans=0;
	void dfs(int x){
		if(x>n){
			long long sum=0;
			for(int i=1;i<=n;i++){
				std::set<int> s=bfs(i);
				for(int j=0;j<=n;j++){
					if(!s.count(j)){sum+=j;break;}
				}
			}
			ans=std::max(ans,sum);
			/*
			for(int i=1;i<=n;i++) printf("%d ",a[i]);
			puts("");
			printf("%lld\n",sum);
			*/
			return ;
		}
		for(int i=0;i<n;i++){
			a[x]=i;
			dfs(x+1);
			a[x]=0;
		}
	}
	void solve(){
		dfs(1);
		printf("%lld\n",ans);
	}
}
namespace Better{
	int a[N];
	int q[N],dep[N],h[N],size[N];
	void bfs(int rt){
		for(int i=0;i<=n;i++) size[i]=dep[i]=h[i]=q[i]=0;
		int l=1,r=0;
		q[++r]=rt;
		while(l<=r){
			int x=q[l++];
			//printf("!%d\n",x);
			for(int i=g.head[x];i;i=g.next[i]){
				int y=g.to[i];
				if(par[x]!=y){
					dep[y]=dep[x]+1;
					//printf("%d->%d",x,y);
					q[++r]=y;
				}
			}
		}
		for(int i=n;i>=1;i--){
			int x=q[i];
			size[x]++;
			///printf("%d %d %d\n",x,par[x],size[par[x]]);
			size[par[x]]+=size[x];
			h[par[x]]=std::max(h[par[x]],h[x]+1);
		}
	}
	struct rec{
		int rd,dep,id;
		friend bool operator < (const rec &a,const rec &b){
			if(a.dep!=b.dep) return a.dep>b.dep;
			return a.rd>b.rd;
		}
	}b[N];
	void solve(){
		
		bfs(1);
		for(int i=1;i<=n;i++){
			//printf("%d %d\n",i,size[i]);
		}
		for(int i=1;i<=n;i++){
			if(rd[i]) b[i]=(rec){rd[i],dep[i],i};
			else b[i]=(rec){rd[i],0,i};
		}
		std::sort(b+1,b+n+1);
		int ans=0;
		int x=b[1].id;
		while(x){
			ans+=size[x];
			x=par[x];
		}
		printf("%d\n",ans+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		par[1]=0;
		g.init();
		for(int i=2;i<=n;i++){
			scanf("%d",&par[i]);
			rd[par[i]]++;
			g.insert(i,par[i]),g.insert(par[i],i);
		}
		if(n<=7) Force::solve();
		else Better::solve();
	}
	return 0;	
}
