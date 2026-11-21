#include<bits/stdc++.h>
using namespace std;
long long n,q,cha[100005];bool col[100005];
vector<long long> v[100005];
void dg(long long dd){
	for(long long t:v[dd]){
		cha[t]+=cha[dd];
		dg(t);
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++){
		long long a;cin>>a;
		//v[i].push_back(a);
		v[a].push_back(i+1);
	}
	string cols;cin>>cols;
	for(int i=0;i<cols.size();i++){
		col[i+1]=int(cols[i]-'0');
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		long long a;cin>>a;
		cha[a]++;
	}
	dg(1);
	for(int i=1;i<=n;i++){
		if((col[i]&&cha[i]%2==0)||(!col[i]&&cha[i]%2==1)){
			cout<<1;
		}
		if((col[i]&&cha[i]%2==1)||(!col[i]&&cha[i]%2==0)){
			cout<<0;
		}
	}
	
	return 0;
}
