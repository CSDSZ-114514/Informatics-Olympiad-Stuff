#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+5;
int n,nx[2*N],ans;
string s,s1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>s;
	s1=s;
	reverse(s1.begin(),s1.end());
	s=" "+s1+"|"+s;
	for(int i=2,j=0;i<=2*n+1;i++)
	{
		while(j&&s[i]!=s[j+1]){
			j=nx[j];
		}
		if(s[i]==s[j+1]){
			j++;
		}
		nx[i]=j;
	}
	cout<<n-nx[2*n+1];
	return 0;
}