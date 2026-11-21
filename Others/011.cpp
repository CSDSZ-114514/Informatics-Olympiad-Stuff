#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s1;
		if(s1.size()>s2.size()){
			s2=s1;
		}
	}
	cout<<s2;
	return 0;
}
