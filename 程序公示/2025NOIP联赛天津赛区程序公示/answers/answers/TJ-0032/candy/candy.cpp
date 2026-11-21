#include <bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
	long long x,y,both;
};
node v[1100000];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long ans=0;
	long long min1=1e18;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;++i){
		scanf("%lld%lld",&v[i].x,&v[i].y);
		v[i].both=v[i].x+v[i].y;
		min1=min(min1,v[i].both);
	}
	
	sort(v+1,v+n+1,cmp);
	
	for(long long i=1;i<=n;i++){
		if(min1>v[i].x+v[i+1].x){
			m-=v[i].x;
			ans++;
		}else break;
	}
	ans+=m*2/min1;
	printf("%lld",ans);
	
	return 0;
}
