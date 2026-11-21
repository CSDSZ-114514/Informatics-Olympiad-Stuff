#include<bits/stdc++.h>
using namespace std;
int cnt=0,p=0,n,a[10000005],day,nit;
int main(){
	cin>>n;
	while(cnt<n){
		day++;
		p=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				p++;
				if(p%3==1){
					if(i==n){
						nit=day;
					}
					a[i]=1;
					cnt++;
				}
			}
		}
	}
	cout<<day<<" "<<nit;
}
