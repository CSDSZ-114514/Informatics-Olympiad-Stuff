#include<bits/stdc++.h>
using namespace std;
long long L,R,n;

int main(){
	cin>>n>>L>>R;
	if(R/n==L/n){
		cout<<R%n;
	}
	if(R/n!=L/n){
		cout<<n-1;
	}
	return 0;
}
