#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<string>
#include<cmath>
#include<set>
const int N=50005;
int n,m,L,R;
int a[N];
long long b[N];
namespace Force{
	void solve(){
		unsigned long long sum=0;
		for(int i=1;i<=n;i++){
			long long ans=-0x3f3f3f3f3f3f3f3f;
			for(int len=L;len<=R;len++){
				for(int l=1;l+len-1<=n;l++){
					int r=l+len-1;
					if(l<=i&&i<=r){
						//printf("l%d r%d %d\n",l,r,b[r]-b[l-1]);
						ans=std::max(ans,b[r]-b[l-1]);
					}
				}
			}
			//printf("%d %d\n",i,ans);
			sum^=(unsigned long long )i*ans;
		}
		printf("%llu\n",sum);
	}
}
long long st[N][30];
int l2[N];
namespace Better{
	long long query(int l,int r){
		int k=l2[r-l+1];
		assert(l<=r);
		assert(r-(1<<k)+1<=n);
		return std::max(st[l][k],st[r-(1<<k)+1][k]);
	}
	void solve(){
		
		unsigned long long sum=0;
		for(int i=1;i<=n;i++){
			long long ans=-0x3f3f3f3f3f3f3f3f;
			for(int l=1;l<=std::min(i,n);l++){
				if(std::max(L,i-l+1)<=std::min(R,n-l+1))
					ans=std::max(ans,query(l+std::max(L,i-l+1)-1,l+std::min(R,n-l+1)-1)-b[l-1]);
			}
			//printf("%d %d\n",i,ans);
			sum^=(unsigned long long )i*ans;
		}
		printf("%llu\n",sum);
	}
}
namespace Spe{
	long long s[N],sst[N][30];
	
	long long query(int l,int r){
		int k=l2[r-l+1];
		assert(l<=r);
		assert(r-(1<<k)+1<=n);
		return std::max(sst[l][k],sst[r-(1<<k)+1][k]);
	}
	void solve(){
		for(int i=1;i+L-1<=n;i++){
			
			s[i]=b[i+L-1]-b[i-1];
			//printf("%d\n",s[i]);
		}
		for(int i=1;i<=n;i++) sst[i][0]=s[i];
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				sst[i][j]=std::max(sst[i][j-1],sst[i+(1<<(j-1))][j-1]);
			}
		}
		unsigned long long sum=0;
		for(int i=1;i<=n;i++){
			sum^=(unsigned long long )i*query(std::max(1,i-L+1),i);
		}
		printf("%llu\n",sum);
	}
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	for(int i=1,j=0;i<=n;i++){
		if(1<<(j+1)==i) j++;
		l2[i]=j;
	}
	for(int i=1;i<=n;i++) st[i][0]=b[i];
	
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=std::max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&L,&R);
		//if(L==R) Spe::solve();
		Better::solve();
	}
	
	
	return 0;	
}
