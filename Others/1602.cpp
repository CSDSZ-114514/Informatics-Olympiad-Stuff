#include<bits/stdc++.h>
using namespace std;
int n,m,mn=-1e9;
int a[1000005],f[1000005];deque<int> q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()&&f[i-1]<f[q.back()]){
			q.pop_back();
		}
		
		q.push_back(i-1);
		if(q.front()<i-m){
			q.pop_front();
		}		
		f[i] = f[q.front()] + a[i];
	}    
	int res = 1e9;
	for (int i=n-m+1;i<=n;i++) {
		res = min(res, f[i]);
	}
	cout<<res;
}
