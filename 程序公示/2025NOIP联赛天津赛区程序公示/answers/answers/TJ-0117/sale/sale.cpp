#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mod=998244353;
int a[5005];
bool ok=1;
int qp(int x,int ci){
	if (ci==0) return 1;
	int o=qp(x,ci/2);
	return o*o%mod*(ci%2?x:1)%mod;
}
int dp[105][205];
struct thing{
	int a;
	int w;
} t[105];
bool cmp(thing a,thing b){
	if (a.a*b.w==b.a*a.w) return a.a>b.a;	
	return a.a*b.w>b.a*a.w;
}
void work(){
	ok=1;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if (a[1]!=a[i]) ok=0;
	}
	if (ok==1 || m==2*n-1){
		cout<<qp(2,n)<<"\n";
		return ;
	}
	sort(a+1,a+1+n,greater<int>());
	if (m==2*n-2){
		if (a[n-1]/2>=a[n] || a[n-1]==a[n]) cout<<qp(2,n)<<"\n";
		else cout<<qp(2,n)-1<<"\n";
		return ;
	}
	if (m==2){
		int ans=0;
		int x=n;
		for (int i=1;i<=n;i++){
			if (a[i]*2<=a[1]){
				x=i-1;
				break;
			}
		}
		for (int i=2;i<=x;i++){
			for (int j=i+1;j<=n;j++){
				if (a[i]+a[j]<a[1]){
					ans+=qp(2,n-j+1);
					ans%=mod;
					break;
				}
				if (j==n) ans++;
			}
		}
		cout<<(qp(2,n)-ans+mod)%mod<<"\n";
		return ;
	}
	int aa=0;
	for (int i=0;i<(1<<n);i++){
		int b[15]={},x=i,ans,cnt=0,sum=0;
		for (int j=1;j<=n;j++){
			b[j]=x%2+1;
			x/=2;
		}
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++){
				dp[j][k]=max(dp[j][k-1],dp[j-1][k]);
				if (k>=b[j]) dp[j][k]=max(dp[j][k],dp[j-1][k-b[j]]+a[j]);
			}
		}
		ans=dp[n][m];
		//for (int j=1;j<=n;j++) cout<<b[j]<<" ";
		//cout<<ans<<" ";
		for (int j=1;j<=n;j++){
			t[j].a=a[j];
			t[j].w=b[j];
		}
		sort(t+1,t+1+n,cmp);
		for (int j=1;j<=n;j++){
			if (cnt+t[j].w<=m){
				cnt+=t[j].w;
				sum+=t[j].a;
			}
		}
		if (ans==sum) aa++;
		//cout<<sum<<"\n";
		for (int j=1;j<=n;j++) for (int k=1;k<=m;k++) dp[j][k]=0;
	}
	cout<<aa<<"\n";
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while (t--) work();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

