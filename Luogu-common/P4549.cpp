#include<bits/stdc++.h>
using namespace std;
long long g=0,n=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a=0;
		cin>>a;
		g=__gcd(g,abs(a));
	}
	cout<<g;
	return 0;
}
