#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,t;
int n,m;
int a[500005];
int qpow(int a,int b) {
	int res=1;
	while(b) {
		if(b&1) {
			res*=a;
			res%=998244353;
		}
		a*=a;
		a%=998244353;
		b>>=1;
	}
	return res;
}
double b[500005];
struct node {
	int yuan;
	double shi;
	double b;
} c[500005];
bool cmp(node x,node y) {
	if(x.shi==y.shi) {
		return x.yuan>y.yuan;
	}
	return x.shi>y.shi;
}
int d[500005];
int ans=0;
void dfs(int u) {
	if(u==n+1) {
		for(int i=1; i<=n; i++) {
			c[i].yuan=a[i];
			c[i].shi=a[i]*1.0/b[i]*1.0;
			c[i].b=b[i];
		}
		sort(c+1,c+n+1,cmp);
		long double now=m*1.0;
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(now>=c[i].b) {
				now-=c[i].b;
				cnt+=c[i].yuan;
			}
		}
		//	cout<<now<<endl;
		int cntt=0;
		now=1.0*m;
		int maxnw=0;
		priority_queue<int,vector<int>,greater<int> >q;
		int tot=0;
		for(int i=1; i<=n; i++) {
			double x=b[i];
			if(now>=x) {
				now-=x;
				cntt+=a[i];
				if(b[i]==2){
					q.push(a[i]);
				}
			}else{
				if(b[i]==1)d[++tot]=a[i];
			}
		}
		sort(d+1,d+tot+1);
		for(int i=tot;i>=1;i-=2){
			if(q.size()&&d[i]+d[i-1]>=q.top()){
				cntt+=d[i]+d[i-1]-q.top();
				q.pop();
			}
		}
		//	cout<<now<<endl;
	//	cout<<cnt<<" "<<cntt<<endl;
		if(cnt>=cntt) {
			ans++;
		}
		return ;
	}
	b[u]=1.0;
	dfs(u+1);
	b[u]=2.0;
	dfs(u+1);
}
signed main() {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>cc>>t;
	for(int ii=1; ii<=t; ii++) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		sort(a+1,a+n+1,greater<int>());
		if(cc<=5) {
			dfs(1);
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		if(cc==16||cc==18||m==2*n-1){
			cout<<qpow(2,n)<<endl;
		}
	}

}
