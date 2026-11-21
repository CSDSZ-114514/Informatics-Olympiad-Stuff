#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=b;i>=a;i--)
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll n,m,x[N],y[N],a[N],minn,ans=0,sum[N],kil[N],kilc=0;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	minn=0x3f3f3f3f3f;
	rep(i,1,n){
		cin>>x[i]>>y[i];
		sum[i]=x[i]+y[i];
		if(x[i]==y[i]) kil[++kilc]=x[i];
	}
	//step.1捆绑售卖 留点东西 
	sort(sum+1,sum+1+n);
	ans+=(m/sum[1])*2;
	m=(m%sum[1]);
//	rep(i,1,n){
//		if(m>=sum[i]){
//			ans+=(m/sum[i])*2;
//			m=m%sum[i];
//		}
//	}
	//算梭哈次数
	sort(x+1,x+1+n);ll temst;
	ll cntx=0,cnts=0,suha=0;
	for(int i=1;i+1<=n;i+=2){//1 3
		if(x[i]+x[i+1]<sum[1]){
			suha++;
			m+=sum[1];
			m-=x[i]+x[i+1]; 
			temst=i+1;
		}
	}
	rep(i,temst,n){
		kil[++kilc]=x[i];
	}
//	cout<<suha<<endl;
	ans+=(m/sum[1])*2;
	m=(m%sum[1]);
	//step.2凑数（贪心!）
//	int ans2=ans;
//	int m2=m;
//	//方案1:直接开始凑数 
	sort(kil+1,kil+1+kilc);
//	cout<<endl<<m<<' '<<kil[1]<<' '<<kilc;
	rep(i,1,kilc){
		if(m>=kil[i]){
			ans++;
			m-=kil[i];
		}
	}
//	cout<<endl<<m<<' '<<kil[1]<<' '<<kilc<<endl;
	//默认不梭哈，一下把在凑数
//	rep(i,1,n){
//		if(m>=x[i]){
//			ans++;
//			m-=x[i];
//		}
//	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
