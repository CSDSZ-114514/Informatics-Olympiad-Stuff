#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],c=6;
int main(){
	int n=0;
	cin>>n;
	a[1]=3;
	b[1]=3;
	a[2]=5;
	b[2]=8;
	a[3]=9;
	b[3]=17;
	for(int i=4;i<=50;i++){
		a[i]=a[i-1]+c;
		c+=2;
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	cout<<b[n];
}
