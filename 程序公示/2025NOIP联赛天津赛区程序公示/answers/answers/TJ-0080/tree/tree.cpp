#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,ans=1;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(m==1){
			ans=n;
			cout<<ans<<endl;
		}else{
			cout<<(2*n-1)<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
