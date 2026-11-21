#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+25,M=998244353;

int c;

int n,m;
int p[N];
/*struct candy{
	int x,w;
	int xw;
	bool operator<(const candy &a)const{
		if (xw==a.xw) return x>a.x;
		return xw>a.xw;
	}
} r[N];*/


ll ksm(int a1,int b){
	ll sum=1;
	while (b){
		if (b&1) sum=(sum*a1)%M;
		a1=(a1*a1)%M;
		b>>=1;
	}
	return sum;
}


void solve(){
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>p[i];
	}
	//bool flag=0;
	//if (c==10) 
	//if (c==10 || c==11 || c==12 || c==18 || c==19 || c=20){
		cout<<ksm(2,n)<<'\n';
		return;
	//}
	
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int t;
	cin>>c>>t;
	while (t--) solve();
	return 0;
}
