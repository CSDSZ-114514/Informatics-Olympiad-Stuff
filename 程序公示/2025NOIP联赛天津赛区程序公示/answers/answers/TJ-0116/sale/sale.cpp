#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<string>
#include<cmath>
const int N=5005,mod=998244353;
int c,T,n,m;
int a[N];
namespace Force{
	const int NN=105;
	struct rec{
		int x,y,id;
		friend bool operator < (const rec &a,const rec &b){
			if((long long)a.x*b.y!=(long long)b.x*a.y) return (long long)a.x*b.y>(long long)b.x*a.y;
			if(a.x!=b.x) return a.x>b.x; 
			return a.id<b.id; 
		}
	}t[N];
	long long me[NN][NN];
	bool hm[NN][NN];
	long long dfs(int x,int y){
		if(x>n) return 0;
		if(hm[x][y]) return me[x][y];
		long long ans=0;
		if(y>=t[x].y) ans=std::max(ans,dfs(x+1,y-t[x].y)+t[x].x);
		ans=std::max(ans,dfs(x+1,y));
		hm[x][y]=true;
		return me[x][y]=ans;
	}
	void solve(){
		long long cnt=0;
		for(int s=0;s<(1<<n);s++){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=m;j++){
					hm[i][j]=false;
				}
			}
			for(int i=1;i<=n;i++){
				t[i].x=a[i],t[i].y=(s>>(i-1)&1)+1,t[i].id=i;
				//printf("%d ",t[i].y);
			}
			//puts("");
			long long maxans=dfs(1,m);
			std::sort(t+1,t+n+1);
			int now=m;
			long long sum=0;
			for(int i=1;i<=n&&now;i++){
				if(now>=t[i].y) now-=t[i].y,sum+=t[i].x;
			}
			//printf("%lld %lld\n",sum,maxans);
			if(sum==maxans) cnt++;
		}
		printf("%lld\n",cnt);
	}
}
namespace SpeA{
	void solve(){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(c==18||c==16) SpeA::solve();
		else Force::solve();
	}
	return 0;	
}
