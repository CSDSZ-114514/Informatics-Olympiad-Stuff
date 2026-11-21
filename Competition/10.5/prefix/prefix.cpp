#include<bits/stdc++.h>
using namespace std;
long long t[2505][35],cnt[100005],idx;
void insert(string s) {
	int p=0; 
	for(int i=0;i<s.size();i++) { 
		int j=s[i]-'A';
		if(t[p][j]){
			p=t[p][j];
		} else{
			t[p][j]=++idx; 
			p=idx;
		}
	}
	cnt[p]++; 
} 
string s;
bool f[1000005];
int main(){
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	while(true){
		string s;
		cin>>s;
		if(s==".")break;
		insert(s);
	}
	f[0]=true;
	string pt;
	while(cin>>pt){
		s+=pt;
	}
	//cout<<s;
	long long ans=0;
	long long n=s.size();
	for(long long i=0;i<n;i++){
		if(!f[i])continue;
		ans=max(ans,i);
		long long p=0;
		for(int j=0;i+j<n&&j<10;j++){
			int c=s[i+j]-'A';
			if(!t[p][c])break;
			p=t[p][c]; 
			if(cnt[p])f[i+j+1]=true; 
		}
	}
	if(f[n])ans=n;
	cout<<ans;
	return 0;
} 
