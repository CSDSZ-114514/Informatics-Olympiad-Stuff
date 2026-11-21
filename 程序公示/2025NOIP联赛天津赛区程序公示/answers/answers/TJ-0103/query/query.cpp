#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int len;
	long long n,m;
	cin>>len;
	for(int i=0;i<len;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<3;i++)
	{
		cin>>n>>m;  
		long long num=0;
		num=pow(2,(m-n));
		cout<<num;
	}
	return 0;
}
