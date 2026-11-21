#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<string>
#include<cmath>
const int N=100005;
int n;
long long m;
int a[N][2];
namespace Force{
	const int NN=1005;
	long long me[NN][2][NN];
	bool hm[NN][2][NN];
	long long dfs(int x,int f,int y){
		if(x>n) return 0;
		if(hm[x][f][y]) return me[x][f][y];
		long long ans=0;
		if(y>=a[x][f]) ans=std::max(ans,dfs(x,f^1,y-a[x][f])+1);
		ans=std::max(ans,dfs(x+1,0,y));
		hm[x][f][y]=true;
		return me[x][f][y]=ans;
	}
	void solve(){
		printf("%lld\n",dfs(1,0,m));
		
	}
}
namespace Better{
	struct rec{
		int v,type;
		friend bool operator < (const rec &a,const rec &b){
			return (long long)a.v*b.type<(long long)b.v*a.type;
		}
	}b[N<<1];
	int pre[N<<1];
	bool f[N<<1];
	int find(int x) { return !f[pre[x]]?pre[x]:pre[pre[x]]=find(pre[x]);}
	void solve(){
		for(int i=1;i<=n;i++){
			b[i]=(rec){a[i][0]+a[i][1],2};
		}
		for(int i=1;i<=n;i++){
			b[i+n]=(rec){a[i][0],1};
		}
		
		std::sort(b+1,b+2*n+1);
		
		for(int i=1,j=0;i<=2*n;i++){
			if(b[i].type==1) j=i;
			pre[i]=j;
		}
		
		long long ans=0,last=m;
		int hs1=0;
		for(int i=1;i<=2*n;i++){
			
			if(b[i].type==2){
				long long tmp=(long long)(last/b[i].v);
				if(hs1){
					int p=find(i);
					if(p&&(long long)((last+b[p].v)/b[i].v)*2-1>tmp*2){
						last+=b[p].v;
						hs1--,tmp=(long long)(last/b[i].v),f[p]=true;
						ans+=tmp*2-1,last-=tmp*b[i].v;
					}else{
						ans+=tmp*2;
						last-=tmp*b[i].v;
					}
				}else{
					ans+=tmp*2;
					last-=tmp*b[i].v;
				}
				
			}else{
				if(last>=b[i].v) last-=b[i].v,ans++,hs1++;
				
			}
			
		}
		
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	Better::solve();
	return 0;	
}
