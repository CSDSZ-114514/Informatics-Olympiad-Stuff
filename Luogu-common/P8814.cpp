#include<bits/stdc++.h>
using namespace std;
int n,e,d,q,p,s,a2;
int main(){
	cin>>s;
	for(int i=1;i<=s;i++){
		cin>>n>>e>>d;
		a2=1;
		for(q=1;q<=sqrt(n);q++){
			p=n/q;
			if(n%q==0){
				if(p+q==n-e*d+2){
					cout<<q<<" "<<p<<endl;
					a2=0;
					break;
				}
			}
		}
		if(a2){
			cout<<"NO"<<endl;
		}
			
	}
	
	return 0;
}
