#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tree.in","w",stdin);
	freopen("tree.out","r",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	long long n;
	for(int T=0;T<t;T++)
	{
		cin>>n;
		int k;
		cin>>k;
		for(int I=0;I<n-1;I++) cin>>k;
		cout<<(n+1)*n/2<<endl; 
	}
	return 0;
}
