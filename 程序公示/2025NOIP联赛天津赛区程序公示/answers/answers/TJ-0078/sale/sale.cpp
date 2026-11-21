#include<bits/stdc++.h>
using namespace std;
long long n,p,m,k[100001],c,t,sum=1;
long long a;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>m>>n;
		for(int i=1;i<=m;i++){
			cin>>k[i];
		}
		for(int i=m;i>=m-n;i--){
			sum*=i;
		}
		for(int i=1;i<=n;i++){
			sum/=i;
		}
		cout<<m*n<<endl;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
