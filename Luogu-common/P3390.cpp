#include<bits/stdc++.h>
#define N 1005
using namespace std;
long long n,k;
//const int N= 105;
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
					p.c[i][j]%=(long long)(1e9+7);
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
			res=a*res;
		}
		b/=2;
		a=a*a;
	}
	return res;
}
int main(){
	cin>>n>>k;
	manbo man;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>man.c[i][j];
		}
	}
	man=qpow(man,k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<man.c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
