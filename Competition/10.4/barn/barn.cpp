#include<bits/stdc++.h>
using namespace std;
long long m,s,c;
long long num[1000005],gap[1000005];
bool cmp(long long x,long long y) {
	return x>y;
}
int main() {
	freopen("barn.in","r",stdin);
	freopen("barn.out","w",stdout);
	cin>>m>>s>>c;
	for(int i=1; i<=c; i++) {
		cin>>num[i];
	}
	sort(num+1,num+1+c);
	long long ans=num[c]-num[1]+1;
	//cout<<ans;
	for(int i=2; i<=c; i++) {
		gap[i]=num[i]-num[i-1]-1;
	}
	sort(gap+2,gap+1+c,cmp);
	if(c<=m){
		cout<<c;
		return 0;
	}
	//for(int i=2;i<=c;i++)cout<<gap[i]<<" "; 
	for(int i=2;i<=m;i++){
		ans-=gap[i];
	} 
	cout<<ans;

	return 0;
}
