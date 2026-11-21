#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[1000000],b[1000000],c[1000000];
string add(string s1,string s2,int x){
	int lena=0; //s1的位数 
	for(int i=s1.size()-1;i>=0;i--){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[lena++]=s1[i]-'0';//给a数组搞上s1的各位 ,顺便给lena赋值 
		}
		if(s1[i]>='A'&&s1[i]<='Z'){
			a[lena++]=s1[i]-'A'+10;//给a数组搞上s1的各位 ,顺便给lena赋值 
		}
	}
	
	int lenb=0;//s2的位数 
	for(int i=s2.size()-1;i>=0;i--){
		if(s2[i]>='0'&&s2[i]<='9'){
			b[lenb++]=s2[i]-'0';//给a数组搞上s1的各位 ,顺便给lena赋值 
		}
		if(s2[i]>='A'&&s2[i]<='Z'){
			b[lenb++]=s2[i]-'A'+10;//给a数组搞上s1的各位 ,顺便给lena赋值 
		}
	}
	
	int lenc=max(lena,lenb);//定义和的位数 
	for(int i=0;i<=lenc-1;i++){//lenc-1是索引，地址那个 
		c[i]+=a[i]+b[i];//c[i]是下文的c[i+1]，所以+= 
		c[i+1]=c[i]/x;//判断进不进1 
		c[i]=c[i]%x;//判断本位是多少 
	}
	if(c[lenc]!=0){
		lenc++;//看进不进位调整和的位数 
	}
	string res;//结果 
	for(int i=lenc-1;i>=0;i--){
		if(c[i]>=10) {
			res= res + char(c[i]-10+'A');
		}  else {
			res=res+to_string(c[i]);
		}
	}
	 return res;
}
int main(){
	int a;
	string s1,s2;
	cin>>a>>s1>>s2;
	cout<<add(s1,s2,a);
} 
