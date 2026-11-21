#include<bits/stdc++.h>
using namespace std;
string s1,s2;int sum;
int main(){
	cin>>s1;
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			if(s1[i+1]!=s2[i+1]&&i!=s1.size()-1){
				swap(s1[i],s1[i+1]);
				sum+=1;
			}else{
				s1[i]=s2[i];
				sum++;
			}
		}
	}
	cout<<sum;
}
