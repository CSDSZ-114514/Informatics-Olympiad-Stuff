#include<bits/stdc++.h>
using namespace std;
string s1;
int main(){
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if((s1[i]>='A'&&s1[i]<='Z')||(s1[i]>='a'&&s1[i]<='z')){
			s1[i]+=1;
			if(s1[i]>'z'){
				s1[i]-=26;
			}
			if(s1[i]<'a'&&s1[i]>'Z'){
				s1[i]-=26;
			}
		}
	}
	cout<<s1;
}
