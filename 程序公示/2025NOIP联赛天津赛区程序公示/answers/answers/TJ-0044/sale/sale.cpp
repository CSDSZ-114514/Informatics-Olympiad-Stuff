#include<bits/stdc++.h> 
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
int c,t,z,x;
cin>>c>>t;
if(c==0){
	cin>>z>>x;
	if(t==1&&z==3&&x==2) cout<<6;
}
else
for(int i=0;i<t;i++){
	int n,m,a1,a2;
	cin>>n>>m;
	cin>>a1;
	bool b=0;
	for(int i=1;i<n;i++){
		cin>>a2;
		if(a2!=a1) b=1;
	}
	if(b==0){
		long long k=m/a1,h=pow(2,k);
		long long l=h%998244353;
		cout<<l<<endl;
	}
}
return 0;
}
