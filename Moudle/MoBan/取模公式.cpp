#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,n,s=1e9+7;
	cin>>n>>a;
	cout<<(n%s)*(a%s)%s;
	//(a+b)%c=((a%c)+(b%c))%c
	//(axb)%c=((a%c)x(b%c))%c
	return 0;
} 
