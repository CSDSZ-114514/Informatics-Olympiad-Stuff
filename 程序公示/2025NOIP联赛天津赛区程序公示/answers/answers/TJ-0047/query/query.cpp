#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unsigned __int64 p=1;
int const N=50010;
int n,q;
ll a[N],s[N],w[N],res;

ll MOD(ll x){
	if (x<0) x+=p;
	return x%p;
}

void solve(int d){
	ll tmp;
	for (int i=1;i<=n;i++) w[i]=LONG_LONG_MIN;
	res=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<i+d && j<=n;j++){
			tmp=s[j]-s[i-1];
			//printf("%d ",tmp);
			for (int k=i;k<=j;k++){
				if (w[k]<tmp) w[k]=tmp;
			}
		}
		//printf("\n");
	}
	for (int i=1;i<=n;i++) printf("%d ",w[i]);
	for (int i=1;i<=n;i++){
		printf(".");
		res=res^(w[i]*i);
	}
	return;
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	for (int i=1;i<=64;i++) p*=2;
	cout<<p;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	scanf("%d",&q);
	int l,r;
	for (int i=1;i<=q;i++){
		scanf("%d %d",&l,&r);
		solve(r-l+1);
		printf("%lld\n",res);
	}
	
	return 0;
} 
