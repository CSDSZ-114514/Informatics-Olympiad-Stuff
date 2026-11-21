#include <bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int a[N];
struct ddd{
	double c;
	int f;
}cp[N];
bool cmp(ddd x,ddd y){
	if(x.c==y.c) return x.f>y.f;
	return x.c>y.c;
}
int f1[1<<11],f2[1<<11];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					cp[j].c=a[j]*1.0/2;
					cp[j].f=2;
				}
				else{
					cp[j].c=a[j];
					cp[j].f=1;
				}
			}
//			for(int j=1;j<=n;j++){
//				cout<<cp[j].c<<" ";
//			}
//			cout<<endl;
			sort(cp+1,cp+1+n,cmp);
//			for(int j=1;j<=n;j++){
//				cout<<cp[j].c<<" ";
//			}
//			cout<<endl;
			long long t=m;
			double su=0,sum=0;
			for(int j=1;j<(1<<n);j++){
				t=m;su=0;
				for(int k=1;k<=n;k++){
					if(j&(1<<(k-1))){
						if(cp[k].f==2){
							if(t>=2){
								t-=2;
								su=su+cp[k].c*2;
							}
						}
						else{
							if(t>=1){
								t-=1;
								su=su+cp[k].c;	
							}
						}
					}
					if(t>=0){
						if(sum<su) sum=su;
					}
				}
			}
		//	cout<<sum<<endl;
			double ss=0,tt=m;
			for(int j=1;j<=n;j++){
				if(cp[j].f==2){
					if(tt>=2){
						tt-=2;
						ss+=cp[j].c*2;	
					}
				}
				else{
					if(tt>=1){
						tt-=1;
						ss+=cp[j].c; 	
					}
					
				} 
			}
			//cout<<ss<<endl;
			if(ss==sum) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
