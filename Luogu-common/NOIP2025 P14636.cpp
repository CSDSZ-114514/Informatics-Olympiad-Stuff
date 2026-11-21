#include<bits/stdc++.h>
using namespace std;
long long c,t; 
long long n,m;
long long ans;
bool chs[100005];
struct CD{
	long long nu,a,w;
	double xjb;
}cd[100005],be[100005];
bool cmp(CD x,CD y){
	if(x.xjb==y.xjb){
		if(x.a==y.a){
			return x.nu<y.nu;
		}
		return x.a>y.a;
	}
	return x.xjb>y.xjb;
}
long long dg2(long long x,long long cost){
	if(cost>m){
		return -1;
	}
	if(x==n+1){
		long long sig=0;
		//cout<<endl;
		for(int i=1;i<=n;i++){
			//cout<<chs[i]<<" ";
			if(chs[i]){
				sig+=be[i].a;
			}
		}
		
		return sig;
	}
	long long mx1=0,mx2=0;
	chs[x]=1;
	mx1=dg2(x+1,cost+be[x].w);
	chs[x]=0;
	mx2=dg2(x+1,cost);
	return max(mx1,mx2);
}
void dg(long long x){
	if(x==n+1){
		//cout<<endl;cout<<endl;
		for(int i=1;i<=n;i++){
			cd[i].xjb=cd[i].a*1.0/cd[i].w*1.0;
			be[i]=cd[i];
			//cout<<be[i].w<<" ";
		}
		//cout<<endl;
		sort(be+1,be+1+n,cmp);
		long long tempm=m,sigma=0;//It's the beauty of the Mathematic.
		//cout<<tempm;
		for(int i=1;i<=n;i++){
			if(tempm>=be[i].w){
				tempm-=be[i].w;
				sigma+=be[i].a;
			}
		}
		long long ddd=dg2(1,0);//cout<<ddd<<" "<<sigma<<endl;
		if(sigma==ddd){
			ans++;ans=ans%998244353;
		}
		return ;
	}else{
		cd[x].w=1;
		dg(x+1);
		cd[x].w=2;
		dg(x+1);
	}
}

int main(){ 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t; 
	while(t--){
		ans=0;
		memset(cd,0,sizeof(cd));
		//memset(be,0,sizeof(be));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>cd[i].a;
			cd[i].nu=i;
		}
		dg(1);
		ans=ans%998244353;
		cout<<ans%998244353;
	}
	//NOIP2025 RP++!
	return 0;
}






























































