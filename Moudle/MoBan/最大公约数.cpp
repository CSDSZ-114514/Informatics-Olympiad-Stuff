#include<iostream>
#include<algorithm> //__gcdµÄ 
using namespace std;
int gcd(int a,int b){
	int temp;
	while(a%b!=0){
		temp = a;
		a=b;
		b=temp%a;
	}
	return b;
}
int main(){
	int a,b,ans;
	cin>>a>>b;
	ans=gcd(a,b);
	cout<<ans<<endl;
	//
	cout<<__gcd(a,b);
	return 0;
}
