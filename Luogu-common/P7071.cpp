#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],k=1;

int main(){
	cin>>n;
	if(n%2==1){
		cout<<-1;
		return 0;
	}else{
		n/=2;
		int s=0;
		while(n!=0){
			k*=2;
			if(n%2==1){
				a[++s]=k;
			}
			n/=2;
		}
		for(int i=s;i>=1;i--){
			cout<<a[i]<<' ';
		}
	}
	return 0;
}
