#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],md[1000005],t[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];t[a[i]]++;
		maxx = max(maxx,a[i]);
	}
	for(int i=1;i<=maxx;i++){
		if(t[i]){
			for(int j=1;i*j<=maxx;j++){
				md[i*j]+=t[i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<md[a[i]]-1<<'\n';
	}
}
