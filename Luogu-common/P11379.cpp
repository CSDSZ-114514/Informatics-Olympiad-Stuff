#include<bits/stdc++.h>
using namespace std;
long long n,k,maxn;bool isb[1000005];vector<long long> v[100005];
void dfs(long long dd,long long fa,long long cnt1,long long cnt2){
	if(cnt2>k){
		return ;
	}
	maxn=max(maxn,cnt1);
	for(long long t:v[fa]){
		if(t==dd){
			continue;
		}
		if(isb[t]){
			dfs(fa,t,cnt1+1,cnt2+1);
		}else{
			dfs(fa,t,cnt1+1,cnt2);
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>isb[i];
	}
	for(int i=1;i<=n-1;i++){
		long long a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(isb[i]){
			dfs(0,i,1,1);
		}else{
			dfs(0,i,1,0);
		}
	}
	cout<<maxn;
	return 0;
}
