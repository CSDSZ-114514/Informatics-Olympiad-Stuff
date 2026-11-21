#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define mid ((l+r)>>1)
using namespace std;
const int N=5e5+5,mod=1e9+7;
int n,m,rest,minn=1e18,maxn=-1e18;
struct node{
	int a,b,w;
}a[N];
priority_queue<pair<int,int> >q;
inline int read(){int x(0),f(1);char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return x*f;}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
//	int cc=clock();
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i].a=read(),a[i].b=read();
		a[i].w=a[i].a+a[i].b;
		minn=min(minn,a[i].w);
		maxn=max(maxn,a[i].w);
		rest+=a[i].a;
	}
	int ss=(m-rest)/minn;
	int rst=m-max(0ll,ss)*minn,res=max(0ll,ss)*2,ans=0;
	for(int i=1;i<=n;i++) q.push({-a[i].a,i});
	while(!q.empty()){
		auto t=q.top();q.pop();
		if(-t.first<=rst){
			rst+=t.first;
			res++;
			if(t.second<=n) q.push({-a[t.second].b,t.second+n});
			else q.push({-a[t.second-n].a,t.second-n});
		}
		else break;
	}
//	printf("%lld ",res);
	ans=max(ans,res);
	
	ss=m/minn;
	rst=m-max(0ll,ss-2)*minn,res=max(0ll,ss-2)*2;
//	printf("%lld ",minn);
	for(int i=1;i<=n;i++) q.push({-a[i].a,i});
	while(!q.empty()){
		auto t=q.top();q.pop();
		if(-t.first<=rst){
			rst+=t.first;
			res++;
			if(t.second<=n) q.push({-a[t.second].b,t.second+n});
			else q.push({-a[t.second-n].a,t.second-n});
		}
		else break;
	}
//	printf("%lld ",res);
	ans=max(ans,res);
	
	rst=m-max(0ll,ss-1)*minn,res=max(0ll,ss-1)*2;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) q.push({-a[i].a,i});
	while(!q.empty()){
		auto t=q.top();q.pop();
		if(-t.first<=rst){
			rst+=t.first;
			res++;
			if(t.second<=n) q.push({-a[t.second].b,t.second+n});
			else q.push({-a[t.second-n].a,t.second-n});
		}
		else break;
	}
//	printf("%lld ",res);
	ans=max(ans,res);
	
	rst=m-max(0ll,ss)*minn,res=max(0ll,ss)*2;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) q.push({-a[i].a,i});
	while(!q.empty()){
		auto t=q.top();q.pop();
		if(-t.first<=rst){
			rst+=t.first;
			res++;
			if(t.second<=n) q.push({-a[t.second].b,t.second+n});
			else q.push({-a[t.second-n].a,t.second-n});
		}
		else break;
	}
//	printf("%lld ",res);
	ans=max(ans,res);
	printf("%lld",ans);
//	printf("\n%lld",clock()-cc);
	return 0;
}
/*
3 15
1 7
2 3
3 1

*/
