#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e3+10,mod=998244353;

int n,m,arr[N],ans,crr[N],dp[N];
double brr[N];
struct node{
	double cmp;
	int cst,val;
	friend bool operator<(const node x,const node y){
		if(x.cmp==y.cmp){
			if(x.val==y.val){
				return 1;
			}
			return x.val>y.val;
		}
		return x.cmp>y.cmp;
	}
}drr[N];

void DFS(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++){
			drr[i]=(node){brr[i],crr[i],arr[i]};
		}
		sort(drr+1,drr+1+n);
		int t=m,a1=0,a2=0;
		for(int i=1;i<=n;i++){
			t-=drr[i].cst;
			if(t<0){
				if(drr[i].cst!=2)break;
				t+=drr[i].cst;
				if(t==1){
					continue;
				}else{
					break;
				}
			}
			a1+=drr[i].val;
		}
		t=m;
		for(int i=1;i<=m;i++)dp[i]=-0x3f3f3f3f;
		dp[0]=0;
		a2=0;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=crr[i];j--){
				dp[j]=max(dp[j],dp[j-crr[i]]+arr[i]);
				a2=max(a2,dp[j]);
			}
		}
		//cout<<a1<<' '<<max(dp[m],dp[m-1])<<endl;
		if(a1==a2)ans++;
		return ;
	}
	brr[x]=arr[x];
	crr[x]=1;
	DFS(x+1);
	brr[x]=1.0*(double)arr[x]/2.0;
	crr[x]=2;
	DFS(x+1);
	return ;
}

void init(){
	ans=0;
	memset(arr,0,sizeof arr);
	memset(brr,0,sizeof brr);
	memset(crr,0,sizeof crr);
	return ; 
}

signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c;
	cin>>c;
	if(c<=5){
		int T;
		cin>>T;
		while(T--){
			init();
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>arr[i];
			}
			sort(arr+1,arr+1+n);
			DFS(1);
			cout<<ans%mod<<endl;
		}
	}
	
	return 0;
}
