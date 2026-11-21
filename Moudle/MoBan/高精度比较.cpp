#include<iostream>
#include<cmath>
using namespace std;
char compare_char(string s1,string s2){
	char res;
	
	if(s1.size()==s2.size()){
		if(s1==s2){
			res = '=';
		}else if(s1>s2){
			res = '>';
		}else if(s1<s2){
			res = '<';
		}
	}else if(s1.size()>s2.size()){
		res = '>';
	}else if(s1.size()<s2.size()){
		res = '<';
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

int main(){
	string a,b;
	//getline(cin,a);
	//getline(cin,b);
	cin>>a>>b;
	cout<<compare_char(a,b);
	return 0;
} 
