#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e4+10;
int a[N],ans[N],n,q;
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)a[i]+=a[i-1];
	
	scanf("%lld",&q);
	while(q--){
		int L,R;
		scanf("%lld%lld",&L,&R);
		memset(ans,-0x7f,sizeof(ans));
		for(int len=L;len<=R;++len){
			for(int left=1;left+len-1<=n;++left){
				int right=left+len-1;
				int sum=a[right]-a[left-1];
				for(int i=left;i<=right;++i)
					ans[i]=max(ans[i],sum);
			}
		}
		
		unsigned long long res=0;
		for(int i=1;i<=n;++i)res^=(i*ans[i]);
		cout<<res<<'\n';
	}
	return 0;
}
