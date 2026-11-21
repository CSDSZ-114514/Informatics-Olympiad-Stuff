#include<bits/stdc++.h>
using namespace std;
long long n,used[10005],ans;
string str[10005];
long long check(string s1,string s2){
	for(int i=1;i<min(s1.size(),s2.size());i++){
		if(s1.substr(s1.length()-i,i)==s2.substr(0,i)){
			return i;
		}
	}
	return 0;
}
void dfs(string s,long long len){
	ans=max(ans,len);
	for(int i=1;i<=n;i++){
		
		if(used[i]<=1){
			int l=check(s,str[i]);
			if(l>0){
				used[i]++;
				dfs(str[i],len+str[i].size()-l);
				used[i]--;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i];
	}
	string a="";
	cin>>a;
	dfs(" "+a,1);
	cout<<ans;
	return 0;
}
