#include<iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define ll long long
const int N=5e4+10;
int n;
ll a[N];
ll f[N][33];
int lowbit(int x){
	return x&(-x);
}
void add(ll x,int pos){
	while(pos<=n){
		a[pos]+=x;
		pos+=lowbit(pos);
	}
}
ll getsum(int pos){
	if(pos==0) return 0;
	ll res=0;
	while(pos){
		res+=a[pos];
		pos-=lowbit(pos);
	}
	return res;
}
void init(){
	for(int i=1;i<=n;i++) f[i][0]=getsum(i)-getsum(i-1);
	for(int j=1;j<=(int)log2(n);j++){
		for(int i=n; i-(1<<j)+1 >= 1; i--){
			f[i][j]=max(f[i][j-1],f[i-(1<<(j-1))][j-1]+getsum(i)-getsum(i-(1<<(j-1))));
		}
	}
}
ll F(int pos,int L,int R){
	//cout<<"pos=="<<pos<<"\n";
	ll ans;
	bool flag=0;
	for(int i=pos; max(1,i-R+1)<=pos && i<=n; i++){//iÊÇÓÒ¶Ëµã 
		//×ó¶Ëµã·¶Î§
		int lef=max(1,i-R+1),rig=min(pos,max(1,i-L+1));
		if(i-rig+1<L) continue;
		//cout<<"("<<lef<<","<<rig<<") to "<<i<<"\n";
		int len=log2(rig-lef+1);
		int mxg=max(f[rig][len],f[lef+(1<<len)-1][len]+getsum(rig)-getsum(lef+(1<<len)-1));
		if(!flag){
			ans=mxg+getsum(i)-getsum(rig);
			flag=1;
		}else{
			ans=max(ans, mxg+getsum(i)-getsum(rig));
		}
	}
	return ans;
	/*
	ll ans=0;
	bool flag=0;
	for(int lef=1;lef<=n;lef++){
		for(int rig=lef;rig<=n;rig++){
			if(pos<lef || pos>rig) continue;
			if(rig-lef+1>=L && rig-lef+1<=R)
				if(flag) ans=max(ans, getsum(rig)-getsum(lef-1));
				else ans=getsum(rig)-getsum(lef-1), flag=1;
		}
	}*/
}
int main(){
	
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(x,i);
	}
	init(); 
	int q;
	scanf("%d",&q);
	while(q--) {
		int L,R;
		cin>>L>>R;
		unsigned long long ans=0ull;
		for(int i=1;i<=n;i++){//O(qn^2)
			ll k=F(i, L, R);
			//cout<<k<<" ";
			ans = (ans ^ ((unsigned long long)i * (unsigned long long)k));
		}
		cout<<ans<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
