#include<bits/stdc++.h>
#define N 105
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
	long long a,a1,a2;long long p,q;
	cin>>p>>q;
	cin>>a2>>a1;
	cin>>a>>m;manbo man;
	
	man.c[1][1]=p;man.c[2][1]=q;man.c[1][2]=1;
	if(a==2){
		man=man*man;
	}else if(a==1){
	}else{
		man=qpow(man,a-2);
	}
	cout<<(a1*man.c[1][1]+a2*man.c[2][1])%m;
	return 0;
}
