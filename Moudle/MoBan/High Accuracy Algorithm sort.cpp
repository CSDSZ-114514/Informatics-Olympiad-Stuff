#include<iostream>
#include<algorithm>
using namespace std;
string a[10000];
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
bool cmp(string x,string y){
	if(compare_int(x,y)==-1) {
		return true;
	}else{
		return false;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
