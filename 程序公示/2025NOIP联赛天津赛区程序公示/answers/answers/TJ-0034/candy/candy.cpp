#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
int n,m;
int minn,kind;
int a[N],b[N];

int solve1(int dis){
	int res=(m/minn)*2-2*dis; 
	int left=m%minn+minn*dis;
	for(int i=1;i<=n;++i){
		if(left>=a[i]){
			left-=a[i];
			res++;
		}
		else break;
	}
	return res;
}

int solve2(int dis,int left){
	int res=(m/minn)*2-2*dis-1;
	int nleft=left+minn*dis;
	for(int i=1;i<=n;++i){
		if(nleft>=a[i]){
			nleft-=a[i];
			res++;
		}
		else break;
	}
	return res;
}

signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	minn=2147483647;
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&a[i],&b[i]);
		if(a[i]+b[i]<minn){
			minn=a[i]+b[i];
			kind=i;
		}
	}
	
	int left=0,right=m/minn;
	sort(a+1,a+n+1);
	while(right-left>2){
		int mid1=left+(right-left)/3;
		int mid2=right-(right-left)/3;
		int val1=solve1(mid1),val2=solve1(mid2);
		if(val1>val2)right=mid2;
		else if(val1<val2)left=mid1;
		else left=mid1,right=mid2;
	}
	int ans1=0;
	for(int i=left;i<=right;++i)ans1=max(ans1,solve1(i));
	
	int remain=m%minn+b[kind];
	swap(a[kind],b[kind]);
	sort(a+1,a+n+1);
	left=0,right=m/minn-1;
	while(right-left>2){
		int mid1=left+(right-left)/3;
		int mid2=right-(right-left)/3;
		int val1=solve2(mid1,remain);
		int val2=solve2(mid2,remain);
		if(val1>val2)right=mid2;
		else if(val1<val2)left=mid1;
		else left=mid1,right=mid2;
	}
	int ans2=0;
	for(int i=left;i<=right;++i)ans2=max(ans2,solve2(i,remain));
	
	printf("%lld\n",max(ans1,ans2));
	return 0;
}
