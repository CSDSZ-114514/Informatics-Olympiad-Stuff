#include <iostream>
#include <cstdio>
using namespace std;
long long n,q,l,r;
long long a[50010];
long long sum[50010];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<0<<endl;
	}
	return 0;
} 
