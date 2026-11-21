#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define RLL register LL
#define PLL pair<LL,LL>
#define mp make_pair
const LL N=1e5+10;
LL n,m,num=9e18,mx,ans;

struct NODE{
	LL x,y;
	inline bool operator < (const NODE &nx){
		return x<nx.x;
	}
} a[N];

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(RLL i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
		num=min(num,a[i].x+a[i].y);
	}
	sort(a+1,a+n+1);
	for(RLL i=1;i<=n && m>=a[i].x && (a[i].x<<1)<=num;++i){
		mx=i;
		m-=a[i].x;
		++ans;
	}
	ans+=(m/num)<<1;
	m-=m/num*num;
	while(++mx<=n && m>=a[mx].x){
		m-=a[mx].x;
		++ans;
	}
	if(a[mx].x+m>=num){
		++ans;
	}
	cout<<ans;
	return 0;
}
