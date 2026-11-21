#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct ab{
	int a,b;
}a1[100005];
int dp(long long now,int ij,int tang){
	int ans=0,ba=0;
	bool flag=0;
	if(ij>=n+1){
		return tang;
	}
	if(now==0){
		return tang;
	} 
	int ls=a1[ij].a+a1[ij].b;
	ans=(now/ls)*2;
	if(now-(ans/2)*ls>a1[ij].a){
		ans++;
		flag=1;
	}
	if(flag==0){
		ba=dp(now-(ans/2)*ls,ij+1,tang+ans);
		ba=max(ba,dp(now-a1[ij].a,ij+1,tang+1));
		ba=max(ba,dp(now-(ans/2)*ls+a1[ij].b,ij+1,tang+ans-1));
		ba=max(ba,dp(now,ij+1,tang));
	}
	if(flag==1){
		ba=dp(now-(ans/2)*ls-a1[ij].a,ij+1,tang+ans);
		ba=max(ba,dp(now-a1[ij].a,ij+1,tang+1));
		ba=max(ba,dp(now-(ans/2)*ls,ij+1,tang+ans-1));
		ba=max(ba,dp(now-(ans/2)*ls+a1[ij].b,ij+1,tang+ans-2));
		ba=max(ba,dp(now,ij+1,tang));
	}
	return ba;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	bool flag1=0;
	int minn=1000000000;
	for(int i=1;i<=n;i++){
		cin>>a1[i].a>>a1[i].b;
		minn=min(minn,a1[i].a);
		if(a1[i].a!=a1[i].b){
			flag1=1;
		}
	}
	if(flag1==0){
		cout<<m/minn;
		return 0;
	}
	cout<<dp(m,1,0);
	return 0;
}
