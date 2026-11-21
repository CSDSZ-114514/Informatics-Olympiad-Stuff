#include<bits/stdc++.h>
using namespace std;
//const long long p=(long long)1e10+7;
long long n,m;
long long c[1000015][15];
void init() {
	for(int i=0; i<=1000005; i++) {
		c[i][0] = 1;
	} 
	for(int i=1; i<=1000005; i++) {
		for(int j=1; j<=5; j++) {
			c[i][j] = (c[i-1][j] + c[i-1][j-1]);
		}
	} 
}
long long getc(long long cn,long long cm){
	return c[cn][cm];
}
int main(){
	cin>>m>>n;
	m++;n++;
	init();
	long long ans=getc((m)*(n),3)-(m)*getc((n),3)-(n)*getc(m,3);
	long long ans2=0;
	for(int dx=1;dx<=m-1;dx++){
		for(int dy=1;dy<=n-1;dy++){
			ans2=ans2+(__gcd(dx,dy)-1)*(n-dy)*(m-dx);
		}
	}
	ans2*=2;
	//cout<<ans<<" "<<ans2<<endl;
	cout<<ans-ans2;
	return 0;
}
