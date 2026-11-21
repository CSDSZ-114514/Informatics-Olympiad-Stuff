#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define mid ((l+r)>>1)
using namespace std;
const int N=5e5+5,mod=998244353;
int n,a[N],sum[N],l,r,q[N],res[N],maxn[N<<2];
inline int read(){int x(0),f(1);char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return x*f;}
void build(int k,int l,int r){
	maxn[k]=-2e18;
	if(l==r) return ;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void update(int k,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R){
		maxn[k]=max(maxn[k],d);
		return;
	}
	if(L<=mid) update(k<<1,l,mid,L,R,d);
	if(mid<R) update(k<<1|1,mid+1,r,L,R,d);
}
int query(int k,int l,int r,int x){
	if(l==r) return maxn[k];
	int res=maxn[k];
	if(x<=mid) res=max(res,query(k<<1,l,mid,x));
	else res=max(res,query(k<<1|1,mid+1,r,x));
	return res;
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
//	int cc=clock();
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
	int Q=read();
	while(Q--){
		int ll=read(),rr=read();
		if(ll==rr){
			for(int i=1;i<=n;i++) res[i]=-2e18;
			l=1,r=0;
			ull ans=0;
			for(int i=1;i<=n;i++){
				if(i+ll-1<=n){
					res[i]=sum[min(i+ll-1,n)]-sum[i-1];
					while(l<=r&&res[q[r]]<res[i]) r--;
					q[++r]=i;
				}
				while(l<=r&&q[l]+ll-1<i) l++;
				ans=ans^(1ull*i*res[q[l]]);
			}
			printf("%llu\n",ans);
			continue;
		}
//		for(int i=1;i<=n;i++) res[i]=-2e18;
		build(1,1,n);
		for(int i=1;i<=n;i++){
			for(int len=ll;len<=rr&&i+len-1<=n;len++){
				int j=i+len-1;
				update(1,1,n,i,j,sum[j]-sum[i-1]);
//				for(int k=i;k<=j;k++) res[k]=max(res[k],s);
			}
		}
		ull ans=0;
		for(int i=1;i<=n;i++) ans=ans^(1ull*i*query(1,1,n,i));
		printf("%llu\n",ans);
	}
//	printf("\n%lld",clock()-cc);
	return 0;
}
/*10
2 4 -5 1 5 3 -9 -3 -5 4
6
1 1
3 3
4 4
5 5
6 6
7 7

*/
