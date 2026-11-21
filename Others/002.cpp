#include<bits/stdc++.h>
using namespace std;
int  a[200005] ,n,num;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[a[i]]==i&&a[i]!=i){
			num++;
		}
	}
	cout<<num/2;
	return 0;
}
