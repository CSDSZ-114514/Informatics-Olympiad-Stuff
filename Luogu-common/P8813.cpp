#include<bits/stdc++.h>
using namespace std;
long long a,b,sum;

int main(){
	cin>>a>>b;
	sum=a;
	if(a==1){
		cout<<1;
		return 0;
	}
	for(int i=2;i<=b;i++){
		sum*=a;
		if(sum>1000000000){
			cout<<-1;
			return 0;
		}
	}
	cout<<sum;
}
