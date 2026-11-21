#include<iostream>
#include<algorithm> 
#include<cmath>
using namespace std;
bool prime_number(long long a){
	if(a==1){
		return false;
	}else{
		for(int i=2;i<=sqrt(a);i++){
			if(a%i==0){
				return false;
			}
		}
		return true;
	}
	
}
int main(){
	long long a;
    cin>>a;
	if(prime_number(a)){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}
