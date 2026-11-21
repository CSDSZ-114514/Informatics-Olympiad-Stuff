#include<bits/stdc++.h>
using namespace std;
long long ksm(long long a,long long b,long long p){
	long long ans=1;
	if(p==0)return 0;
	while(b>0){
		if(b%2==1){
			if(a==0)return 0;
			ans=ans*a%p;
		}
		b/=2;
		if(a==0)return 0;
		a=a*a%p;
	}
	return ans;
}
long long e,f,g;
int main(){
	cin>>e>>f>>g;
	cout<<e<<"^"<<f<<" mod "<<g<<"="<<ksm(e,f,g);
}
