#include<bits/stdc++.h>
using namespace std;
long long n,t[1000005],cnt,len;
struct CO{long long x,t,y;}c[1000005];
bool cmp(CO x,CO y){if(x.x==y.x)return x.y<y.y;return x.x<y.x;}
int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x,t,y;cin>>x>>t;y=t-x;
		if(y<0)continue;
		c[++cnt].x=x;c[cnt].t=t;c[cnt].y=y;
	}
	sort(c,c+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		long long l=1,r=len+1,x=c[i].y;
		while(l<r){
			long long mid=(l+r)>>1;
			if(t[mid]<=x)l=mid+1;
			else r=mid;
		}
		t[l]=x;
		if(l>len)len++;
	}
	cout<<len;
} 
