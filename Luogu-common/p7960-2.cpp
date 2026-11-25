#include<bits/stdc++.h>
using namespace std;
bool nav[10000005];
long long T,x; 
bool check(long long x){
	string s=to_string(x);
	for(int i=0;i<s.length();i++){
		if(s[i]=='7')return true;
	}
	return false;
}
long long nxt[10000005];
int main(){
	for(int i=1;i<=10000005;i++){
		if(nav[i])continue;
		if(check(i)){
			for(int j=1;j*i<=10000005;j++){
				nav[i*j]=1;
			}
		}
	}
	long long lst=-1;
	for(int i=10000005;i>=1;i--){
		if(nav[i]){
			nxt[i]=-1;
		}else{
			nxt[i]=lst;
			lst=i;
		}
	} 
	cin>>T;
	while(T--){
		long long x;cin>>x;
		if(nxt[x]!=-1)cout<<nxt[x]<<endl;
		else cout<<nxt[x]<<endl;
	}
	return 0;
}
