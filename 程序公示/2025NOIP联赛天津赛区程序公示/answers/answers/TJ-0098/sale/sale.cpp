#include <bits/stdc++.h>
using namespace std;
int c,t;
void sdf(int x){
	int s=1;
	for(int i=x;i>1;i--){
		s*=i;
	}
	cout<<s<<endl;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,m;
		int a[1005]={0};
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sdf(n);
	}
	return 0;
}
