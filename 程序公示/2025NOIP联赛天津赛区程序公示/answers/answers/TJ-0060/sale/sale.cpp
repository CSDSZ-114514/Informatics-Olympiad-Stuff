#include<bits/stdc++.h>
#define int long long
using namespace std;
struct candy{
	int a;
	int w;
} ;    
bool comp(const candy& c,const candy& b){
	if(c.a*b.w==b.a*c.w){
		return c.a>b.a;
	}
	return c.a*b.w>b.a*c.w;//jiangxv
} 
int pw(int a,int n){
	int res=1,t=a;
	while(n>1){
		if(n%2) res*=t;
		n=n/2;
		t*=t;
	}
	res*=t;
	return res;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int N,T;
	cin>>N>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		int t=pw(2,n);
		candy d[5005];
		int av[5005];
		int ans=t;
		for(int i=1;i<=n;i++){
			cin>>d[i].a;
		}
		for(int i=0;i<t;i++){
			candy c[5005];
			for(int j=1;j<=n;j++){
				c[j].a=d[j].a;
			}
			int k=i,m1=m;
			for(int j=1;j<=n;j++){
				if(k%2) c[j].w=2;
				else c[j].w=1;
				k=k/2;
			}
			sort(c+1,c+1+n,comp);
			int reg=0;
			bool wrong=false;
			for(int j=1;j<=n&&m1;j++){
				if(m1==1&&c[j].w==2){
					int reg=0,reg1=0;
					for(int l=j+1;l<=n;l++){
						if(c[l].w=1){
							reg=l;
							break;	
						} 
					}
					for(int l=j-1;l>=1;l--){
						if(c[l].w=1){
							reg1=l;
							break;	
						} 
					}
					if((reg==0&&c[j].a>c[j-1].a)||(reg1&&c[reg].a+c[reg1].a<c[j].a)) wrong=true;
					break;
				}
				if(m1&&m1>=c[j].w) m1=m1-c[j].w;
			}
			if(wrong) ans--; 
		}
		cout<<ans<<endl;
	}
	return 0;
} 

