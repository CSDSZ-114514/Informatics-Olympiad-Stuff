#include<bits/stdc++.h>
using namespace std;
long long x[100005],y[100005];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m,k=9000000000000000000;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		k=min(k,x[i]+y[i]);
	}
	sort(x+1,x+n+1,cmp);
	long long ans=m/k*2;
	long long sum=0;
	for(long long i=1;i<=n;i++){
		sum+=x[i];
		if(sum>m){
			break;
		}
		ans=max(ans,i+(m-sum)/k*2);
	}
	cout<<ans;
	return 0;
}
