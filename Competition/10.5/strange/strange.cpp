#include<bits/stdc++.h>
using namespace std;
int main(){
	long long r1,r2,m1=4e8,m2=4e8-1;
	cout<<"? "<<m1<<endl;
	cin>>r1;
	cout<<"? "<<m2<<endl;
	cin>>r2;
	cout<<"! "<<r1+m1*(((r2-r1)%m2+m2)%m2)<<endl;
	return 0;
}
