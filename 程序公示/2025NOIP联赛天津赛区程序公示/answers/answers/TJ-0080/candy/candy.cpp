#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=0,now=0,o=1;
int x[210000],minn=INT_MAX;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int xx,yy;
		cin>>xx>>yy;
		minn=min(minn,(xx+yy));
		if(xx<minn){
			x[o]=xx;
			o++;
		}
	}
	sort(x+1,x+o);
	ans=(m/minn)*2;
	now=m%minn;
	int i=1;
	while(1){
		for(;(now>=x[i])&&(i<o);i++){
			now-=x[i];
			ans++;
		}
		if((i+1)>=o){
			break;
		}
		if((x[i]+x[i+1])<(now+minn)){
			now=minn+now-(x[i]+x[i+1]);
		}else{
			break;
		}
		i+=2;
	}
	cout<<ans;
	return 0;
} 
