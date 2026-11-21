#include<bits/stdc++.h>
using namespace std;
int n,p,m,k[100001],sum;
long long a;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>p;
	for(int i=1;i<=p;i++){
		cin>>n>>m;
		for(int i=1;i<=n-1;i++){
			cin>>k[i];
			sum+=k[i];
		}
		cout<<sum+3;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
