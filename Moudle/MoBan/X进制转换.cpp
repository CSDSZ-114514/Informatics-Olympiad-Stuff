#include<iostream>
#include<cmath>
using namespace std;
string TenToX(int number,int x){
	string s;
	if(number == 0){
		s=char(0+'0');
		
	}
	while(number!=0){
		s = char(number%x+'0') + s;
		//s = to_string(number%2) + s;
		number=number/x;
	}
	return s;
};
long long XToTen(string number,int x){
	long long ans = 0;
	for(long long i=0;i<number.size();i++){
		ans += (number[i]-'0')*(pow(x,number.size()-1-i)); 
	} 
	return ans;
};
int main(){
	int a,b,c,t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		if(a==0){
			cout<<TenToX(c,b)<<endl;
		}
		if(a==1){
			cout<<XToTen(to_string(c),b)<<endl;
		}
	}
	
	return 0;
} 
