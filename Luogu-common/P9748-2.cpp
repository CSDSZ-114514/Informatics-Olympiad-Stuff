#include<bits/stdc++.h>
using namespace std;
int cnt=0,p=0,n,day,nit;
double dob;bool boolf=true;
int main(){
	cin>>n;
	while(n){
		day++;
		
		if(n%3==1&&boolf){
			nit=day;
			boolf=false;
		}n-=((n-1)/3+1);
	}
	cout<<day<<" "<<nit;
}
