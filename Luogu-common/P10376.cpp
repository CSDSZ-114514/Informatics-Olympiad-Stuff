#include<bits/stdc++.h>
using namespace std;
#define pp %1000000007
long long n,a,b,c,f[200005];
int main(){
	cin>>n>>a>>b>>c;
	if(n==c){
		cout<<1<<endl;
		return 0;
	}
	f[n]=1;long long ans=0;
	for(int i=n;i>c-max(a,b);i--){
		if(i<0){
			ans+=(f[i+a]pp);
			ans+=(f[i+b]pp);
			ans=ans pp;
			continue;
		}
		if(i+a>=c&&i+a<=n){
			f[i]=(f[i]+f[i+a]pp)pp;
		}
		if(i+b>=c&&i+a<=n){
			f[i]=(f[i]+f[i+b]pp)pp;
		}
		//cout<<2;
	}
	for(int i=max(c-max(a,b),(long long)0);i<=c;i++){
		ans=(ans+(f[i]pp))pp;
		//cout<<1;
	}
	cout<<ans;
}
