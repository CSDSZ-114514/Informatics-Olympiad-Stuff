#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
	cin>>t;
	while(t--){
		long long x,y;
		cin>>x>>y;
		cout<<max((long long)0,-3*x+y)<<" "<<(y-2*x)/2<<endl;
	}
	return 0;
}
