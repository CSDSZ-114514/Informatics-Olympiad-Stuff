#include<bits/stdc++.h>
using namespace std;
long long n,p,q;
int main(){
	cin>>n>>p>>q;
	for(int i=1;i<=n;i++){
		long long x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<endl;
			continue;
		}else if(x==1||y==1){
			cout<<p<<endl;
			continue;
		}else if(__gcd(x,y)==1){
			cout<<min(p,2*q)<<endl;
			continue;
		}else if(__gcd(x,y)!=1){
			cout<<min(q,2*p)<<endl;
			continue;
		}
		
	}
}
