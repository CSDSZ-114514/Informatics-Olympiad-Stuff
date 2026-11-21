#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=b;i>=a;i--)
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll n,m,c,t;
ll C(int x,int y){//C(5,3)
	ll ans=1;
	pre(i,x-y+1,x){
		ans*=i;
	}
//	cout<<ans;
	pre(i,1,y){
		ans/=i;
	}
	return ans;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=0;m=0;int duck;
		cin>>n>>m;
		rep(i,1,n) cin>>duck;
		ll q=m-n;
		if(q<0){
			q=-q;
			cout<<C(n,q)%998244353<<endl;continue;
		}else{
			ll temfina=1;
			q=min(n,q);
			rep(i,1,q){
				temfina+=C(n,i);
			}
			cout<<temfina%998244353<<endl;continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
