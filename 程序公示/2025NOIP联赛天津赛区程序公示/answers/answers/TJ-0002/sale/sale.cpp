#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5500;
const int mod=998244353;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int c,t,n,m,a[N],op[N],f[N],ans=0;
struct node{
	int a,op;
}x[N];
bool cmp(node a,node b){
	if(a.a*(3-a.op)!=b.a*(3-b.op))return a.a*(3-a.op)>b.a*(3-b.op);
	return a.op>b.op;
}
bool cmp2(int a,int b){
	return a>b;
}
void solve(){
	for(int i=1;i<=n;++i){
		x[i].a=a[i];
		x[i].op=op[i];	
	}
	int tmp=m;
	sort(x+1,x+n+1,cmp);
	for(int i=1;i<=n;++i)f[i]=0;
	for(int i=1;i<=n;++i){
		if(tmp>=x[i].op){
			tmp-=x[i].op;
			f[i]=1;
		}
	}
	int num=-1;
	int num1=-1,num2=-1;
	for(int i=n;i>=1;--i){
		if(f[i]==0 and x[i].op==2){
			num=x[i].a;
		}
		if(f[i]==1 and x[i].op==1){
			if(num1==-1)num1=x[i].a;
			else if(num2==-1)num2=x[i].a;
		}
	}
//	for(int i=1;i<=n;++i)cout<<op[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;++i){
//		cout<<x[i].a<<" "<<x[i].op<<":"<<f[i]<<endl;
//	}
//	cout<<num1<<" "<<num2<<"::"<<num<<endl;
	if(tmp==1)num2=0;
	if(num1!=-1 and num2!=-1 and num!=-1 and num1+num2<num){
		++ans; 
//		for(int i=1;i<=n;++i)cout<<op[i]<<" ";
//		cout<<'\n'; 
	}
	
}
void dfs(int step){
	if(step==n){
		solve();
		return ;
	}
	op[step+1]=1;
	dfs(step+1);
	op[step+1]=2;
	dfs(step+1);
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		if(c<=5){
			ans=0;
			dfs(0);
	//		cout<<ans<<endl;
			cout<<pow(2,n)-ans<<'\n';
			continue;			
		} 
		if(c==0 or c==7 or c==8 or c==9 or c==14 or c==15){
			sort(a+1,a+n+1,cmp2);
			ans=0;
//			for(int i=1;i<=n;++i)cout<<a[i]<<" ";
//			cout<<'\n';
			for(int i=2;i<=n;++i){
				if(a[i]*2<=a[1])break;
				int id=n+1;
				for(int j=i+1;j<=n;++j){
					if(a[i]+a[j]<a[1]){
						id=j; 
						break;
					}
				} 
//				cout<<i<<" "<<id<<endl;
//				cout<<qpow(2,n+1-id)<<endl;
				int num=n+1-id;
//				cout<<num<<endl;
				ans+=qpow(2,num);
				ans%=mod;
			}
			ans=qpow(2,n)-ans;
			ans=(ans%mod+mod)%mod;
			cout<<ans<<'\n';
//			return 0;
			continue;
		} 
		if(c==17){
			ans=0;
			for(int i=1;i<=n;++i)op[i]=2;
			for(int i=1;i<=n;++i){
				op[i]=1;
				solve();
				op[i]=2;
			}
			cout<<qpow(2,n)-ans<<'\n';
			continue;
		} 
		if(c==16 or c==18){
			cout<<qpow(2,n)<<'\n';
			continue;
		}
	}
	return 0;
}
