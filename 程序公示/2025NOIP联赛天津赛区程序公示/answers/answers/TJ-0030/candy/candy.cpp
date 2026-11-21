#include<bits/stdc++.h>
using namespace std;
#define int long long
struct pr{
	int p,q,ind;
}a[100001];
int n,m,minn=0x3f3f3f3f,mp=0x3f3f3f3f,mq,mind,ans;
bool cmp(pr a,pr b){
	return a.p<b.p;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].p>>a[i].q;
		a[i].ind=i;
		if(a[i].p+a[i].q<minn||(a[i].p+a[i].q==minn&&a[i].q>mq)){
			minn=a[i].p+a[i].q;
			mp=a[i].p;
			mq=a[i].q;
			mind=a[i].ind;
		}
	}
	ans=m/minn*2;
	m%=minn;
	sort(a+1,a+n+1,cmp);
	int st=2;
	for(int i=1;i<=n;i++){
		if(a[i].p<=m){
			m-=a[i].p;
			ans++;
		}else if(a[i].p+a[i+1].p<minn){
			if(a[i].ind==mind||a[i+1].ind==mind)st^=3;
			m=m+minn-a[i].p-a[i+1].p;
			i++;
		}
		else if(a[i].ind==mind)continue;
		else if(st==1&&a[i].p<mp)m=m+mp-a[i].p;
		else if(st==2&&a[i].p<mq)m=m+mq-a[i].p;
		else break;
	}
	cout<<ans;
	return 0;
} 
