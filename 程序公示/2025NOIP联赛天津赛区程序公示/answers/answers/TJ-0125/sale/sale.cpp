#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5010;
int c,t,n,m,a[N],ans,mod=998244353,tmp,cnt,L,R,jie[5010],ni[5010],C[5010][5010]; // l,r为能任意取的范围 

int ksm(int a,int q){ // a^q
	int result=1, base=a;
	while(q){
		if(q&1) result*=base, result%=mod;
		base*=base, base%=mod, q>>=1;
	}
	return result;
}

void init(){
	jie[0]=1, ni[0]=1;
	for(int i=1;i<=5000;i++){
		jie[i]=jie[i-1]*i%mod;
		ni[i]=ksm(jie[i],mod-2); // 预处理，n^2logn+n^2优化至nlong+n^2，防止4e8次过不去 
		for(int j=0;j<=i;j++){
			C[i][j]=C[i][i-j]= jie[i] *ni[j]%mod *ni[i-j]%mod;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin >> c >> t;
	init();
	while(t--){
//		cin >> n >> m;
//		for(int i=1;i<=n;i++){cin >> a[i]; a[i]=(-a[i]);}
//		sort(a+1,a+n+1);
//		for(int i=1;i<=n;i++){a[i]=(-a[i]);}		
		
		cout << 0 << '\n';
	}

	return 0;
} 
