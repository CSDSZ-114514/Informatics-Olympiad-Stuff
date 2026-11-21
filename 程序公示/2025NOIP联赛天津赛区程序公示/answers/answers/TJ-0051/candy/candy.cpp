#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans=0;
long long x[100100],y[100100],a[100100],c,d,g;
long long mie=0x7fffffff;
int p[100100];
bool f=false;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		if(x[i]+y[i]<mie){
			mie=x[i]+y[i];
			if(x[i]<y[i])f=true;
			else f=false;
			d=y[i];
			c=x[i];
			g=i;
		}else if(x[i]+y[i]==mie && x[i]<c){
			mie=x[i]+y[i];
			if(x[i]<y[i])f=true;
			else f=false;
			d=y[i];
			c=x[i];
			g=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(2*x[i]<mie){
			m-=x[i];
			p[i]=1;
			ans++;
		}
	}
	if(m>=mie){
		ans+=2*(m-m%mie)/mie;
		m=m%mie;
		if(f){
			m+=d;
			ans--;
			p[g]=(p[g]+1)%2;
		}	
	} 
	if(m>0){
		int num=1;
		for(int i=1;i<=n;i++){
			if(p[i]==0){
				if(x[i]<=m){
					a[num]=x[i];
					num++;
				}
			}else if(y[i]<=m){
				a[num]=y[i];
				num++;
			}
		}
		sort(a+1,a+num);		
		for(int i=1;i<num;i++){
			if(m<a[i])break;
			else{
				m-=a[i];
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
