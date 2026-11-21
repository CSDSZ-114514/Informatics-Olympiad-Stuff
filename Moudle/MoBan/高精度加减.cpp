#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[1000000],b[1000000],c[1000000];
string add(string s1,string s2){
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
	
	int lenc=max(lena,lenb);//定义和的位数 
	for(int i=0;i<=lenc-1;i++){//lenc-1是索引，地址那个 
		c[i]+=a[i]+b[i];//c[i]是下文的c[i+1]，所以+= 
		c[i+1]=c[i]/10;//判断进不进1 
		c[i]=c[i]%10;//判断本位是多少 
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
int compare_int(string s1,string s2){
	int res;
	//1> 0= -1<
	if(s1.size()==s2.size()){
		if(s1==s2){
			res = 0;
		}else if(s1>s2){
			res = 1;
		}else if(s1<s2){
			res = -1;
		}
	}else if(s1.size()>s2.size()){
		res = 1;
	}else if(s1.size()<s2.size()){
		res = -1;
	}
	
	return res;
}
string subtrahend(string s1,string s2){
	

	int lena=0; //s1的位数 
	for(int i=s1.size()-1;i>=0;i--){
		a[lena++]=s1[i]-'0';//给a数组搞上s1的各位 ,顺便给lena赋值 
	}
	
	int lenb=0;//s2的位数 
	for(int i=s2.size()-1;i>=0;i--){
		b[lenb++]=s2[i]-'0';//给b数组搞上s2的各位 ,顺便给lenb赋值  
	}
	
	int lenc=max(lena,lenb);//定义差的位数 
	for(int i=0;i<=lenc-1;i++){//lenc-1是索引，地址那个 
		if(a[i]<b[i]){
			a[i+1]--;
			c[i]=a[i]+10-b[i];
		}else{
			c[i]=a[i]-b[i];
		}
	}
	while(c[lenc-1]==0&&lenc>1){
		lenc--;
	}
	string res;//结果 
	for(int i=lenc-1;i>=0;i--){
		res=res+to_string(c[i]);
	}
	return res;
}
string subtrahend_compare(string s1,string s2){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
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
	
	int lena=0; //s1的位数 
	for(int i=s1.size()-1;i>=0;i--){
		a[lena++]=s1[i]-'0';//给a数组搞上s1的各位 ,顺便给lena赋值 
	}
	
	int lenb=0;//s2的位数 
	for(int i=s2.size()-1;i>=0;i--){
		b[lenb++]=s2[i]-'0';//给b数组搞上s2的各位 ,顺便给lenb赋值  
	}
	int lenc=max(lena,lenb);//定义差的位数 
	for(int i=0;i<=lenc-1;i++){//lenc-1是索引，地址那个 
		if(a[i]<b[i]){
			a[i+1]--;
			c[i]=a[i]+10-b[i];
		}else{
			c[i]=a[i]-b[i];
		}
	}
	while(c[lenc-1]==0&&lenc>1){
		lenc--;
	}
	string res;//结果 
	if(com==-1) {
		res += "-";
	}
	for(int i=lenc-1;i>=0;i--){
		res=res+to_string(c[i]);
	}
	return res;
}
int main(){
	int m;
	string n;
	cin>>n;
	cin>>m;
	char ch;
	
	string sum1,sum2=n;
	string ans;
	for(int i=1;i<=m;i++){
		cin>>ch>>n;
		
		if(ch=='-'){
			sum1=add(sum1,n);
			//cout<<"sum1:"<<sum1<<endl;
		}else{
			sum2=add(sum2,n);
			//cout<<"sum2:"<<sum2<<endl;
		}
	}
	ans=subtrahend_compare(sum2,sum1);
	cout<<ans;
	return 0;
	
}
