#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
int T,n,p[N],s,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        s=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>p[i];
		}
        sort(p+1,p+1+n);
		for(int i=1;i<=n;i++){
            a[n-i+1]=p[i]-p[i-1]-1;
        }
		// for(int i=1;i<=n;++i){
		// 	cout<<a[i]<<' ';
		// }
		
		for(int i=1;i<=n;i+=2){
			s^=a[i];
		}
		if(s==0) cout<<"Bob will win";
		else cout<<"Georgia will win";
		cout<<"\n";
	}
	return 0;
}