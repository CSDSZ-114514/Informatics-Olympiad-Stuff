#include<bits/stdc++.h>
using namespace std;
int n,m,mn=-1e9;
int a[1000005],s[1000005];deque<int> q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()&&s[i-1]<s[q.back()]){
			q.pop_back();
		}
		
		q.push_back(i-1);
		if(q.front()<i-m){
			q.pop_front();
		}
		mn=max(mn,s[i]-s[q.front()]);		
	}
	cout<<mn;
}
