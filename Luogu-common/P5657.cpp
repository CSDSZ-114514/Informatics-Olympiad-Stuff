#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull po(ull x,ull y){
	for(ull i=1;i<=y;i++){
		x*=2;
	}
	return x;
}
ull n,k;string str;
void dep(ull len,ull k){
	if(len==1){
		cout<<k;
		return ;
	}
	else{
		if(k<=len/2){
			cout<<'0';
			dep(len/2,k);
		}else{
			cout<<'1';
			dep(len/2,len-k);
		}
	}
}
int main(){
	cin>>n>>k;
	dep(po(1,n)-1,k);
	return 0;
}
