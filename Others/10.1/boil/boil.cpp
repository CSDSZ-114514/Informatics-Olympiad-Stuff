#include<bits/stdc++.h>
using namespace std;
int n;
double ans,nw;
int main(){
	
	freopen("boil.in","r",stdin);
	freopen("boil.out","w",stdout);
	cin>>n;
	nw = 420000*1.0/n;
	for(int i=1;i<=n;i++){
		ans+=nw;
		nw=nw-0.5/i*nw;
	}    
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
} 
