#include<bits/stdc++.h>
using namespace std;
long long a[500005],p[500005],b[3005][3005];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]+a[i];
	}
	long long q;
	cin>>q;
	while(q--){
		long long l,r;
		cin>>l>>r;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				b[i][j]=-9000000000000000000;
			}
		}
		for(long long i=1;i<=n-l+1;i++){
			for(long long j=i+l-1;j<=i+r-1&&j<=n;j++){
				b[i][j]=p[j]-p[i-1];
				//cout<<i<<" "<<j<<" "<<b[i][j]<<"\n";
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=n;j>=1;j--){
				b[i][j]=max(b[i][j],b[i][j+1]);
			}
		}
		for(long long j=1;j<=n;j++){
			for(long long i=1;i<=n;i++){
				b[i][j]=max(b[i][j],b[i-1][j]);
				//cout<<i<<" "<<j<<" "<<b[i][j]<<"\n";
			}
		}
		unsigned long long ans=0;
		for(long long i=1;i<=n;i++){
			//cout<<b[i][i]<<"\n";
			ans^=(unsigned long long)b[i][i]*(unsigned long long)i;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
