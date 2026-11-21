#include<bits/stdc++.h>
using namespace std;
string s1;
int a[100000000],c[100000000],y=0;

string chufa(string s1,int n1){
	string res;
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	int lena=0;
	for(int i=0;i<s1.size();i++){
		a[lena++]=s1[i]-'0';
	}
	int lenc=lena,mod=0;
	for(int i=0;i<=lena-1;i++){
		c[i]=(mod*10+a[i])/n1;
		mod=(mod*10+a[i])%n1;
	}
	int ind=0;
	while(c[ind]==0&&ind<lenc-1){
		ind++;
	}
	for(int i=ind;i<=lenc-1;i++){
		res=res+to_string(c[i]);
	}
	y=mod;
	return res;
}
string TenToX(string  number,int x){
	string s;
	if(number == to_string(0)){
		s=char(0+'0');
		
	}
	while(number!=to_string(0)){
		chufa(number,x);
		s = to_string(y) + s;
		//s = to_string(number%2) + s;
		number=chufa(number,x);
	}
	return s;
};
int main(){
	cin>>s1;
	cout<<TenToX(s1,2);
}
