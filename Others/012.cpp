#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n,a[10005],b;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	while(!q.empty()){
		q.push(q.front());
		q.pop();
		a[q.front()]=++b;
		q.pop();
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
