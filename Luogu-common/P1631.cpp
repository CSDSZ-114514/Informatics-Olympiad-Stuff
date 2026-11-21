#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],b[1000005];
struct nd{
	long long val,ni,nj;
	bool operator <(const nd p) const{
		return val>p.val;
	}
};
priority_queue<nd> q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		q.push({a[i]+b[1],i,1});
	}
	for(int i=1;i<=n;i++){
		cout<<q.top().val<<" ";
		int ti=q.top().ni;int tj=q.top().nj;
		q.pop();
		q.push({a[ti]+b[tj+1],ti,tj+1});
	}
}
