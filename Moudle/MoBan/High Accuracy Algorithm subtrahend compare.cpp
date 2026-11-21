#include<iostream>
using namespace std;
int a[1000000],b[1000000],c[1000000];
string subtrahend_compare(string s1,string s2){
	cout<<"test6:"<<endl; 
	string s3;
	int com;
	//1> 0= -1<
	if(s1.size()==s2.size()){
		if(s1==s2){
			com = 0;
		}else if(s1>s2){
			com = 1;
		}else if(s1<s2){
			com = -1;
			s3=s1;
			s1=s2;
			s2=s3;
		}
	}else if(s1.size()>s2.size()){
		com = 1;
	}else if(s1.size()<s2.size()){
		com = -1;
		s3=s1;
		s1=s2;
		s2=s3;
	}
	
	cout<<"test4:"<<endl;
	int lena=0; //s1的位数 
	for(int i=s1.size()-1;i>=0;i--){
		a[lena++]=s1[i]-'0';//给a数组搞上s1的各位 ,顺便给lena赋值 
	}
	
	int lenb=0;//s2的位数 
	for(int i=s2.size()-1;i>=0;i--){
		b[lenb++]=s2[i]-'0';//给b数组搞上s2的各位 ,顺便给lenb赋值  
	}
	cout<<"test1:"<<endl;
	int lenc=max(lena,lenb);//定义差的位数 
	for(int i=0;i<=lenc-1;i++){//lenc-1是索引，地址那个 
		if(a[i]<b[i]){
			a[i+1]--;
			c[i]=a[i]+10-b[i];
		}else{
			c[i]=a[i]-b[i];
		}
	}
	cout<<"test2:"<<endl;
	while(c[lenc-1]==0&&lenc>1){
		lenc--;
	}
	cout<<"test3:"<<endl;
	string res;//结果 
	cout<<"com:"<<com<<endl;
	if(com==-1) {
		res += "-";
	}
	for(int i=lenc-1;i>=0;i--){
		res=res+to_string(c[i]);
	}
	return res;
}
int main(){
	string a,b;
	//getline(cin,a);
	//getline(cin,b);
	cin>>a>>b;
	cout<<"tst1"<<endl;
	cout<<subtrahend_compare(a,b);
	cout<<"tst2"<<endl;
	return 0;
} 
