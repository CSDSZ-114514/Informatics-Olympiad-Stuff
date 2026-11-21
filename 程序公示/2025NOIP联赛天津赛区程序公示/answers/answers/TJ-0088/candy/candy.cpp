#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
pair<float,int> a[2*N];
int x,y;
int n;
long long m;
long long tot,ans;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[++tot].first=x;
		a[tot].second=1;
		a[++tot].first=(x+y)*1.0/2.0;
		a[tot].second=0;
	}
	sort(a+1,a+tot+1);
//	for(int i=1;i<=n;i++){
//		printf("%.1f %d\n",a[i].first,a[i].second);
//	}
	for(int i=1;i<=tot;i++){
		if(m<a[i].first){
			continue;
		}
		if(a[i].second==1){
			ans+=1;
			m-=a[i].first;
		}
		else if(a[i].second==0){
			ans+=floor(m/(a[i].first*2))*2;
			m-=(floor(m/(a[i].first*2))*2)*a[i].first;
		}
		//printf("%d\n",m);
	}
	printf("%lld",ans);
	return 0;
}
