#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	double sum;
	cin>>n>>m;
	for(int i=n;i<=m;i++){
		sum+=(1.0/(double)pow(i,2));
	} 
	cout<<setprecision(5)<<fixed<<sum;
	return 0;
}
