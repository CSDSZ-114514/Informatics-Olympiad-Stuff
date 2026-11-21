#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define RLL register LL
#define PLL pair<LL,LL>
#define mp make_pair
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs ((u<<1)|1)
const LL N=5e4+10,inf=0x3f3f3f3f3f3f3f3f;
LL n,a[N],f[N][16],maxx[N<<2];
ULL ans;

inline LL find_max(LL l,LL r){
	LL len=(LL)log2(r-l+1.0);
	if(a[f[l][len]]>a[f[r-(1<<len)+1][len]]){
		return f[l][len];
	}
	return f[r-(1<<len)+1][len];
}

void change(LL u,LL l,LL r,LL x,LL y,LL num){
	if(l>y || r<x){
		return;
	}
	if(l>=x && r<=y){
		maxx[u]=max(maxx[u],num);
		return;
	}
	change(ls,l,mid,x,y,num);
	change(rs,mid+1,r,x,y,num);
	return;
}

void work(LL u,LL l,LL r){
	if(l==r){
		ans^=(((ULL)l)*((ULL)maxx[u]));
		maxx[u]=-inf;
		return;
	}
	maxx[ls]=max(maxx[ls],maxx[u]);
	maxx[rs]=max(maxx[rs],maxx[u]);
	work(ls,l,mid);
	work(rs,mid+1,r);
	maxx[u]=-inf;
	return;
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(RLL i=1;i<=n;++i){
		cin>>a[i];
		a[i]+=a[i-1];
		f[i][0]=i;
	}
	for(RLL i=1;(1<<i)<=n;++i){
		for(RLL j=1;j+(1<<i)-1<=n;++j){
			if(a[f[j][i-1]]>a[f[j+(1<<(i-1))][i-1]]){
				f[j][i]=f[j][i-1];
			}else{
				f[j][i]=f[j+(1<<(i-1))][i-1];
			}
		}
	}
	work(1,1,n);
	LL q;
	cin>>q;
	while(q--){
		LL l,r;
		cin>>l>>r;
		for(RLL i=1;i+l-1<=n;++i){
			LL wz=i+l-2;
			while(wz<min(n,i+r-1)){
				LL nwz=find_max(wz+1,min(n,i+r-1));
				change(1,1,n,i,nwz,a[nwz]-a[i-1]);
				wz=nwz;
			}
		}
		ans=0;
		work(1,1,n);
		cout<<ans<<'\n';
	}
	return 0;
}
