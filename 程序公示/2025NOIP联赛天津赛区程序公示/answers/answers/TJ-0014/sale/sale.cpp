#include<bits/stdc++.h>
#define int long long 
using namespace std;
int mod=998244353; 
int ce,t;
int a[10000];
int ans=0;
int inv[5055][5055];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int qpow(int x,int y){
	int res=1;
	while(y>0){
		if(y&1) res=(res*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}
//n!/(n-m)!*m!
int erfen(int l,int r,int va){
	int mid;
	int res=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>=va){
			l=mid+1;
		}else {
			res=mid;
			r=mid-1;
		}
	}
	return res;
}
void solve(){
	for(int i=1;i<=n;i++){
		int cnt=i;
		for(int j=i+1;j<=n;j++){
			if(a[j]*2<a[i]) break;
			else cnt++;
		}
		//cout<<"@"<<cnt<<"\n";
		for(int j=i+1;j<=n;j++){
			if(a[j]*2<a[i]) break;
			for(int k=cnt+1;k<=n;k++){
				if(a[j]+a[k]<a[i]){
				//	cout<<"#"<<i<<" "<<j<<" "<<k<<" ";
				//	cout<<ans<<"\n"; 
					for(int l=0;l<=j-i-1;l++){
						int x=((i-1)*2)-(m-2-l);
						if(x>i-1||x<0)continue;
						ans=(ans+mod-(inv[i-1][x]*inv[j-i-1][l]*qpow(2,n-k+1)))%mod;
					}
					break;
				}
				if(k==n){
					for(int l=0;l<=j-i-1;l++){
						int x=((i-1)*2)-(m-2-l);
						if(x>i-1||x<0)continue;
						ans=(ans+mod-(inv[i-1][x]*inv[j-i-1][l]))%mod;
					}
				//	cout<<i<<" "<<j<<" ";
				//	cout<<ans<<"\n"; 
				}
			}
			if(cnt>=n){
				if(a[i]==a[j]) continue;
				for(int l=0;l<=j-i-1;l++){
					int x=((i-1)*2)-(m-2-l);
					
					if(x>i-1||x<0)continue;
				//	cout<<i<<" "<<j<<" "<<l<<" "<<(inv[i-1][x]*inv[j-i-1][l])<<"\n";
					ans=(ans+mod-(inv[i-1][x]*inv[j-i-1][l]))%mod;
				}
				
			}
		}
	}
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin.tie(0),ios_base::sync_with_stdio(false);
	cin>>ce>>t;
	inv[1][1]=inv[1][0]=1;
	for(int i=0;i<=5000;i++){
		 inv[0][i]=1;
	}
	for(int i=2;i<=500;i++){
		for(int j=1;j<=i;j++){
			if(j==1) inv[i][j]=(inv[i-1][j]*i/(i-j))%mod;
			else inv[i][j]=(inv[i][j-1]*(i-j+1)/j)%mod;
		//	cout<<i<<" "<<j<<" "<<inv[i][j]<<"\n"; 
		}
		inv[i][0]=1;
	}
	while(t--){
		cin>>n>>m;
		ans=qpow(2,n);
	//	cout<<"#";
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		solve();
		cout<<ans<<"\n";
	}
	return 0;
}

