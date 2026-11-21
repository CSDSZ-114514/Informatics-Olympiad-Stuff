#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL N=100005;
LL n,m;
LL ans;
LL temp_ans[N];

struct node{
	LL x,y,sum;
}a[N];

bool cmp(node x,node y){
	return x.sum<y.sum;
}

bool cmp2(node x,node y){
	return x.x<y.x;
}

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
		a[i].sum=a[i].x+a[i].y;
	}
	
	LL M=0;
	for(LL i=1;i<=n;i++) {
		M+=a[i].x;
	}
	
	sort(a+1,a+1+n,cmp);
	
	ans+=m/a[1].sum*2;
	m-=m/a[1].sum*a[1].sum;
	LL temp=a[1].sum;
	sort(a+1,a+1+n,cmp2);
	
	LL temp_m;
	for(LL i=0;i<=N-5;i++) {
		temp_m=m+i*temp;
		if(temp_m>M) break;
		for(LL j=1;j<=n;j++) {
			if(temp_m>=a[j].x){
				temp_m-=a[j].x;
				temp_ans[i]++;
			}
			else break;
		}
	}
	LL maxn=-LLONG_MAX;
	for(LL i=0;i<=N-5;i++) {
		maxn=max(maxn,temp_ans[i]-i*2);
	}
	cout<<ans+maxn;
	return 0;
}
