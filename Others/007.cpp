#include <bits/stdc++.h>
using namespace std;
string s1;
int ans;
int main(){
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='C'){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
