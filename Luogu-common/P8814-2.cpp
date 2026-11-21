#include<bits/stdc++.h>
using namespace std;
long long n,e,d,m,s,k;
int main(){
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>n>>e>>d;
		m=2+n-e*d;
		s=m*m-4*n;
		 long long r = sqrt(s);
		if(r*r==s&&s>=0){
			if((m-r)%2==0){
				cout<<(m-r)/2<<" ";
				cout<<n/((m-r)/2)<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
