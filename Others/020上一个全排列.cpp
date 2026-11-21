#include<bits/stdc++.h>
using namespace std;
int n,a[10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(prev_permutation(a+1,a+n+1)){
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
	}else{
		cout<<"ERROR";
	}
}
