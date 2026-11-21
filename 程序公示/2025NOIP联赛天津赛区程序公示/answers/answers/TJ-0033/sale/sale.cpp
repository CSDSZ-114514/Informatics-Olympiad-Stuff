#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5005 , mod = 998244353;
int qpow(int a,int b){
	b%=(mod-1);
	int ans=1;
	while(b){
		if(b&1) b>>=1; ans=(ans*a)%mod;
		a=(a*a)%mod;
	}
	return ans;
}
int n,m,a[N],t;
int solve(int cnt,int ppos,int pos){
	cout<<cnt<<" "<<ppos<<" "<<pos<<endl;
	if(pos==m-cnt&&a[pos]+a[pos+1]<a[ppos]){
		cout<<"Trap "<<cnt<<" "<<pos<<endl; 
		return qpow(2,n-m);
	}
	if(pos<m-cnt){
		while(a[ppos+1]/2.0<a[pos]&&pos<n) pos++;
		return solve(cnt+1,ppos+1,pos)+solve(cnt,ppos+1,pos);
	}
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		int np,flag=true;
		cin>>a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(a[i]>a[1]/2.0&&flag){
				np=i;
				flag=false;
			}
		}
		sort(a+1,a+1+n,greater<int>());
		cout<<qpow(2,n)-solve(0,1,np)<<endl;
	}
	cout.flush();
	return 0;
}

