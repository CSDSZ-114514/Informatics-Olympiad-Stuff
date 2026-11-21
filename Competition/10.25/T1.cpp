#include<bits/stdc++.h>
using namespace std;
long long T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cout<<1<<endl;
		for(int i=1;i<=n;i++){
			cout<<(1LL<<(i-1))<<" ";
		}
		cout<<endl;
		for(int i=n-2;i>=0;i--) {
        	cout<<(1LL<<n)-1-(1LL<<i)<<" ";
    	}
    	cout<<(1LL<<n)-1<<endl;
	}
	return 0;
} 
