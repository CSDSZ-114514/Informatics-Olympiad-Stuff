#include<bits/stdc++.h>
using namespace std;
int S,f[10005],a[10005];
int yue(int x){
	int ans=0; 
	for(int i=1;i<x;i++){
		if(x%i==0){
			ans+=i;
		}
	}  
	return ans;
}
int main(){
	cin>>S;
	for(int i=2;i<=S;i++){
		a[i]=yue(i);
	}
	for(int i=2;i<=S;i++){
		for(int j=S;j>=i;j--){
			f[j]=max(f[j],f[j-i]+a[i]);
		}
	}
	cout<<f[S];
}
