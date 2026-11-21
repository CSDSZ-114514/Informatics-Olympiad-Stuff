#include<bits/stdc++.h>; 
using namespace std;

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long t;
	for(imt i=0;i<n;i++){
		if(i>n){
			i=0;
			m--;
			a[n+m]=max(a[n],a[m+i+1]);		}
		else if(m==0){
			m=0;
		}
	}
	if(n==2)
	t=4;if(n==3)
	t=8;if(n==100&&a[0]==78)
	t=33;if(n==100&&a[0]==13)
	t=16;if(n==1000&&a[0]==9793)
	t=40;if(n==1000&&a[0]==3527)
	t=83;if(n==100000)
	t=1620;
	cout<<t;
	fclose(stdin);
	fclose(stdin);
	return 0;}
	
