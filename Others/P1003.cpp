#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005],g[100005],k[100005],x,y;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	}
	cin>>x>>y;
	for(int i=n;i>=1;i--){
		if(x<=a[i]+g[i]&&x>=a[i]&&y<=b[i]+k[i]&&y>=b[i]){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}

