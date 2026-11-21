#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[1000000],b[1000000],c[1000000];
string multiplicative(string s1,string s2){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int lena=0; //s1的位数 
	for(int i=s1.size()-1;i>=0;i--){
		a[lena++]=s1[i]-'0';//给a数组搞上s1的各位 ,顺便给lena赋值 
	}
	
	int lenb=0;//s2的位数 
	for(int i=s2.size()-1;i>=0;i--){
		b[lenb++]=s2[i]-'0';//给b数组搞上s2的各位 ,顺便给lenb赋值  
	}
	
	int lenc=lena+lenb-1;
	for(int i=0;i<=lena-1;i++){
		for(int j=0;j<=lenb-1;j++){
			c[i+j]+=a[i]*b[j];
			c[i+j+1]+=c[i+j]/10;
			c[i+j]=c[i+j]%10;
		}
	}
	if(c[lenc]!=0){
		lenc++;//看进不进位调整和的位数 
	}
	string res;//结果 
	for(int i=lenc-1;i>=0;i--){
		res=res+to_string(c[i]);
	}
	 return res;
}
string factorial(int n){
	string res=to_string(n);
	if(n!=0){	
		for(int i=1;i<=n-1;i++){
			res = multiplicative(res,to_string(i));
			cout<<res<<endl;
		}
	}else{
		res = 1;
	}
	return res;
}
string factorial(double n){
	string res=to_string(1);	
	for(int i=2;i<=n;i++){
		res = multiplicative(res,to_string(i));
		cout<<res<<endl;
	}
	return res;
}
int main(){
	double a;
	cin>>a;
	cout<<factorial(a);
	return 0;
}
