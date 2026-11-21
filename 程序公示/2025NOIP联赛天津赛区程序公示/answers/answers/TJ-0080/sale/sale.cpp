#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=998244353;
ll maxx=0,maxxx=0,n,m;
double a[5000];
ll gsm(int x){
	int anss=1;
	while(x--){
		anss*=2;
		anss%=M;
	}
	return anss;
}
bool cmp(double x,double y){
	return x>y;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int b=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1){
				if(a[i]!=a[i-1]){
					b=0;
				}
			}
		}
		if(b){
			cout<<gsm(n)<<endl;
			continue;
		}
		int ans=gsm(n);
		int now=0;
		sort(a+1,a+1+n,cmp);
		for(int i=2;i<n;i++){
			for(int j=n;j>i;j--){
				if((a[j]+a[i])<a[1]){
					now=j;
				}
			}
			if(now==0){
//			cout<<now<<" ";
				continue;
			}
			ll tt=gsm(n-now+1);
//			cout<<now<<" ";
			ans-=tt;
			now=0;
		}
		while(ans<0){
			ans+=M;
		}
		cout<<ans<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
} 
