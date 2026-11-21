#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];deque<int> q;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		while(!q.empty()&&a[i]<a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(q.front()<i-k+1){
			q.pop_front();
		}
		if(i>=k){
			cout<<a[q.front()]<<" ";
		}
	}
	q.clear();cout<<endl;
	for(int i=1;i<=n;i++){
		while(!q.empty()&&a[i]>a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(q.front()<i-k+1){
			q.pop_front();
		}
		if(i>=k){
			cout<<a[q.front()]<<" ";
		}
	}
}
