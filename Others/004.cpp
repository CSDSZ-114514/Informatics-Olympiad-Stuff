#include<bits/stdc++.h>
using namespace std;
int  d,k=1;
int main(){
	cin>>d;
	for(int i=2;i*i<=d;i++){
		while(d%(i*i)==0)
		k*=i,d/=(i*i);//k*sqrt(d)
	}
	cout<<k;
	
}
