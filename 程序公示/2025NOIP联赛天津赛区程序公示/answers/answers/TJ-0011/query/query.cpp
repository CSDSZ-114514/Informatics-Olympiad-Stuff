#include<bits/stdc++.h>
//#define int long long
#define pb emplace_back
#define fi first
#define se second
#define mkp make_pair
#define il inline
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using pii=pair<int,int>;
template<typename T> T& read(T& s){
	s=0;char c;bool flag=0;
	do{c=getchar();if(c=='-')flag=1;}while(!isdigit(c));
	while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();
	if(flag)s=-s;return s;
}
template<typename T> void write(T x){
	if(!x)return putchar(48),void();
	static int St[40],Top;
	if(x<0)putchar('-'),x=-x;
	while(x)St[++Top]=x%10,x/=10;
	while(Top)putchar(St[Top--]^48);
}
template<typename type,typename ...T> void read(type &x,T& ...y){read(x),read(y...);}
const int N=5e4+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,a[N];ll b[N],sum[N],ans[N];
pii que[N];
int q[N],head,tail=-1;
void work(int len){
	for(int i=1;i<=n-len+1;i++){
		b[i]=sum[i+len-1]-sum[i-1];
	}
	head=0,tail=-1;
	for(int i=1;i<=n-len+1;i++){
		while(head<=tail&&b[q[tail]]<b[i])tail--;
		while(head<=tail&&i-q[head]>=len)head++;
		q[++tail]=i;
		ans[i]=b[q[head]];
	}
	ans[n+1]=-inf;
	for(int i=n;i>n-len+1;i--){
		ans[i]=max(ans[i+1],sum[i]-sum[i-len]);
	}
}
int kkk[N][512+5];
il void solve(){
	read(n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+read(a[i]);
	read(m);
	for(int i=1;i<=m;i++)read(que[i].fi,que[i].se);
	bool flag=1;for(int i=1;i<=m;i++)if(que[i].fi!=que[i].se){flag=0;break;}
	if(flag){
		for(int i=1;i<=m;i++){
			work(que[i].fi);
			ull c=0;
			for(ull i=1;i<=n;i++)c^=i*(ull)ans[i];
			write(c),putchar('\n');
		}
		return ;
	}
	while(1)cout<<"CCF I love You.";
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int T=1;
	//read(T);
	while(T--){
		solve();
	}
	return 0;
}

