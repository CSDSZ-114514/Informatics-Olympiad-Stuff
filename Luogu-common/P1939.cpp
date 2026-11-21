#include<bits/stdc++.h>
using namespace std;
const int N=5,p=1e9+7;
long long n=3,t;
struct manbo{
	long long c[N][N];
	manbo(){
		memset(c,0,sizeof(c));
	}
	manbo operator*(manbo x){
		manbo t;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					t.c[i][j] = (t.c[i][j] + c[i][k]*x.c[k][j])%p;
				}
			}
		}
		return t;
	}
};
manbo qpow(manbo a,long long b){
	manbo res;
	for(int i=1;i<=n;i++){
		res.c[i][i]=1;
	}
	while(b>0){
		if(b%2==1){
			res=res*a;
		}
		b/=2;
		a=a*a;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout<<1;
	cin>>t;
	while(t--){
		long long z;
		cin>>z;
		manbo dw,aq;
		aq.c[1][1]=1;aq.c[1][2]=1;aq.c[1][3]=1;
		dw.c[1][1]=1;dw.c[1][2]=1;dw.c[1][3]=0;
		dw.c[2][1]=0;dw.c[2][2]=0;dw.c[2][3]=1;
		dw.c[3][1]=1;dw.c[3][2]=0;dw.c[3][3]=0;
		aq=aq*qpow(dw,z-3);
		cout<<aq.c[1][1]<<'\n';
	}
	return 0;
}
