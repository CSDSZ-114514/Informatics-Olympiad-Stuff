#include<bits/stdc++.h>
using namespace std;
int a,b;
bool ishw(int n){
	string s=to_string(n);
	for(int i=0;i<=s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			//cout<<s[i]<<s[s.length()-i]<<endl;
			return false;
		}
	}
	return true;
}
bool iszs(int n){
	if(n==0)return 0;
	if(n==1)return 0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return 0;
	}
	return 1;
}
int main(){
	cin>>a>>b;
	if(a%2==0)a++;
	b = min(9999999, b);
	//cout<<ishw("1002");
	//cout<<ishw("123454321");
	for(int i=a;i<=b;i+=2){
		if(to_string(i).length()%2==0&&to_string(i).length()!=2)continue;
		//if(i%2==0)continue;
		if(!ishw(i))continue;
		if(!iszs(i))continue;
		printf("%d\n",i);
	}
	//cout<<iszs(1);cout<<iszs(5);cout<<iszs(6);
}
