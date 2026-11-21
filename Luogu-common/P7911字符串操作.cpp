#include<bits/stdc++.h>
using namespace std;
long long n;string op,ad;
map<string,int>m;
bool check(string ip){
	int a=0,b=0,c=0,d=0,e=0;
	int num=sscanf(ip.c_str(),"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e);
	if(num==5){
		if(a<=255&&a>=0&&b<=255&&b>=0&&c<=255&&c>=0&&d<=255&&d>=0&&e<=65535&&e>=0){
			string ip2=to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d)+":"+to_string(e);
			if(ip2==ip){
				return 1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>ad;
		if(op=="Server"){
			if(check(ad)){
				if(m[ad]==0){
					m[ad]=i;
					cout<<"OK"<<endl;
				}else{
					cout<<"FAIL"<<endl;
				}
				
			}else{
				cout<<"ERR"<<endl;
			}
		}if(op=="Client"){
			if(check(ad)){
				if(m[ad]==0){
					cout<<"FAIL"<<endl;
				}else{
					cout<<m[ad]<<endl;
				}
			}else{
				cout<<"ERR"<<endl;
			}
		}
	}
}
