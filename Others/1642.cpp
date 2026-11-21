#include<bits/stdc++.h>
#define N 1005
using namespace std;
long long n=2,m;
struct manbo{
	long long c[N][N];
	manbo(){
		memset(c,0,sizeof(c));
	}
	manbo operator*(manbo x){
		manbo p;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					p.c[i][j]+=((c[i][k]*x.c[k][j]));
					p.c[i][j]%=m;
				}
			}
		}
		return p;
	}
};
manbo qpow(manbo a,long long b){
	manbo res;
	for(int i=1;i<=n;i++){
		res.c[i][i]=1;
	}
	while(b>0){
		if(b%2!=0){
			res=res*a;
		}
		b/=2;
		a=a*a;
	}
	return res;
}
int main(){
	long long a;
	cin>>a>>m;manbo man;
	man.c[1][1]=1;man.c[2][1]=1;man.c[1][2]=1;
	man=qpow(man,a-2);
	cout<<(1*man.c[1][1]+1*man.c[2][1])%m;
	return 0;
}
