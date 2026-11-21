#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int t,cc;
	cin>>cc>>t;
	int n,m;
	int a[10009],b[10009],c[10009];
	int mod=998244353;
	while(t--) {
		int bt=0,ct=0;
		bool u=true;
		int l=0,r=0;
		int j=0,jie=0;
		long long sum=0;
		u=true;
		cin>>n>>m;
		for(int i=0; i<n; i++) {
			scanf("%d",&a[i]);
			if(i!=0&&a[i]!=a[i-1]){
				u=false; 
			}
			a[i]=-a[i];
		}
		sort(a,a+n);
		for(int i=0; i<n; i++) {
			a[i]=-a[i];
		}
		int su=0;
        if(2*n-1==m||u) {
			int su=1;
			for(int i=0; i<n; i++) {
				su*=2;
				su%=mod;
			}
			jie=su;
//			cout<<su<<endl;
		}
		else if(n<=20) {
			for(int i=0; i<(1<<n); i++) {
				bt=0;
				ct=0;
				for(j=0; j<n; j++) {
					if((i>>j)&1) {
						b[bt]=a[j];
						bt++;
					} else {
						c[ct]=a[j];
						ct++;
					}
				}
				b[bt]=0;
				bt++;
				l=r=sum=0;
				while(sum<m) {
					if(l==bt&&r==ct) {
						break;
					}
					if(l==bt) {
						r++;
						sum+=2;
						continue;
					}
					if(r==ct) {
						l++;
						sum++;
						continue;
					}
					if(b[l]*2>c[r]||sum==m-1) {
						l++;
						sum++;
					} else {
						r++;
						sum+=2;
					}
				}
				if(r!=ct&&l>=2&&b[l-1]+b[l-2]<c[r]) {
					su++;
				}
			}
			jie=(1<<n)-su;
//			cout<<(1<<n)-su<<endl;
		} 
		else{
			int su=1;
			for(int i=0; i<n; i++) {
				su*=2;
				su%=mod;
			}
			jie=su;
		}
		printf("%d\n",jie);
	}
	return 0;
}
