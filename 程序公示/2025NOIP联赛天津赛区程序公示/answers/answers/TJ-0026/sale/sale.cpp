//#include<bits/stdc++.h>
//using namespace std;
//
//const int N=5005;
//const long long M=998244353;
//
//struct NODE{
//	long long num;
//	int dt;
//};
//
//bool cmp(NODE x,NODE y){
//	if(x.dt!=y.dt){
//		return x.dt>y.dt;
//	}else{
//		return x.num<y.num;
//	}
//}
//
//long long ksm(long long di,long long vi){
//	long long re=1;
//	while(vi){
//		if(vi&1){
//			re*=di;
//			re%=M;
//		}
//		di*=di;
//		di%=M;
//		vi>>=1;
//	}
//	return re;
//}
//
//int n;
//int m;
//NODE a[N];
//long long pr[N];
//long long mx;
//long long ans;
//
//void dfs(int nd,int mx1,int mx2){
//	if(nd==n+1){
//		if(mx1+mx2==mx){
//			ans++;
//			ans%=M;
//			return;
//		}
//	}
//	pr[nd]=a[nd];
//	if(pr[nd]>mx1){
//		mx2=
//	}
//	
//	
//	pr[nd]=a[nd]>>1;
//}
//
//void nt(){
//	cin>>n>>m;
//	m<<=1;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].dt;
//		a[i].dt<<=1;
//		a[i].num=i;
//	}
//	sort(a+1,a+n+1,cmp);
//
//	mx=a[1].dt+a[2].dt;
//	if(m==2){
//	}else{
//		mx1=0;
//		mx2=0;
//		memset(pr,-1,sizeof(pr));
//		dfs(1);
//	}
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	
//	freopen("sale4.in","r",stdin);
////	freopen("sale.out","w",stdout);
//
//	int c;
//	int t;
//	cin>>c>>t;
//	while(t--){
//		nt();
//	}
//
////	fclose(stdin);
////	fclose(stdout);
//
//
//
//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;

const int N=5005;
const long long M=998244353;

struct NODE{
	long long dt;
	int num;
};

NODE a[N];

bool cmp(NODE x,NODE y){
	if(x.dt!=y.dt){
		return x.dt>y.dt;
	}else{
		return x.num<y.num;
	}
}

long long ksm(long long di,long long vi){
	long long re=1;
	while(vi){
		if(vi&1){
			re*=di;
			re%=M;
		}
		di*=di;
		di%=M;
		vi>>=1;
	}
	return re;
}

void nt(){
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].dt;
		a[i].num=i;
	}
	if(m==2){
		sort(a+1,a+n+1,cmp);
		long long ans=ksm(2,n-1);
		//1 1
		
		//2
		int tw=0;
		for(int i=2;i<=n;i++){
			if((a[i].dt<<1)<=a[1].dt){
				tw++;
			}
		}
		ans+=ksm(2,tw);
		ans%=M;
		cout<<ans<<"\n";
	}else if(m==(n<<1)-1){
		cout<<ksm(2,n);
	}else if(m==(n<<1)-2){
		sort(a+1,a+n+1,cmp);
		int ans=ksm(2,n);
		if((a[n].dt!=a[n-1].dt)&&((a[n].dt<<1)>a[n-1].dt)){
			ans-=1;
		}
		cout<<ans<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);


//	for(int i=1;i<=50;i++){
//		cout<<ksm(2,i)<<"\n";
//	}
	
	int c;
	int t;
	cin>>c>>t;
	while(t--){
		nt();
	}

	fclose(stdin);
	fclose(stdout);



	return 0;
}

