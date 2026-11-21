#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n;
void dg(int x,string s){
	if(x>n){

		return;
	}else{
		
		cout<<s+" "+to_string(x)<<endl;
		dg(x+1,s+" "+to_string(x));
		dg(x+1,s);
	}
}
int main(){
	cin>>n;
	dg(1,"");
	return 0;
}
