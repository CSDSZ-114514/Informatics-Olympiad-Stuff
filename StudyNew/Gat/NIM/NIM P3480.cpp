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
		for(int i=n;i>=1;--i){
            int b = p[i]-p[i-1];   
            if ((n-i+1) % 2 == 1) s ^= b;  
        }
		if(s==0) cout<<"NIE";
		else cout<<"TAK";
		cout<<"\n";
	}
	return 0;
}