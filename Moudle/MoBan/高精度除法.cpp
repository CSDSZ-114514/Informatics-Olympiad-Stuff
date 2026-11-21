#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[1000000],b[1000000],c[1000000];
string divisor(string s1,int n,int mode){
	//mode=1,输出余数
	//mode=0,输出商
	string res;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int lena=0; //s1的位数 
	for(int i=0;i<s1.size();i++){
		a[lena++]=s1[i]-'0';//给a数组搞上s1的各位 ,顺便给lena赋值 
	}
	
	int lenc=lena;
	int x=0;
	for(int i=0;i<=lena-1;i++){
		c[i]=(x*10+a[i])/n;
		x=(x*10+a[i])%n;
	}
	if(mode==1){
		res=to_string(x);
	}else if(mode==0){
		int index=0;
		while(c[index]==0&&index<lenc-1){
			index++;
		}
		for(int i=index;i<lenc;i++){
			res=res+to_string(c[i]);
		}
	}else{
		res = "false";
	}
	return res;
}
int main(){
	string a;
	int b;
	cin>>a>>b;
	cout<<divisor(a,b,0)<<" "<<divisor(a,b,1);
	return 0;
}
