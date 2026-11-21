#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
struct ab{
	int a1,ij,now;
	double bi;
}a[50005];
int c,t,n,m;
bool cmp(ab xx,ab yy){
	if(xx.bi!=yy.bi){
		return xx.bi>yy.bi;
	}
	if(xx.a1!=yy.a1){
		return xx.a1>yy.a1;
	}
	if(xx.ij!=yy.ij){
		return xx.ij<yy.ij;
	}
}
int ans1(){
	int mm=m,ba=0,i=0;
	while(mm>0){
		if(i>=n) break;
		if(mm>=a[i].now){
			mm-=a[i].now;
			ba+=a[i].a1;
		}
		i++;
	}
	return ba;
}
int ans2(int earn,int have,int i){
	if(have==0) return earn;
	if(have<0) return 0;
	if(i>n-1){
		return earn;
	}
	int ba=0;
	ba=ans2(earn,have,i+1);
	ba=max(ba,ans2(earn+a[i].a1,have-a[i].now,i+1));
	return ba;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	if(c==18){
		while(t--){
			cin>>n>>m;
			int ans=1;
			for(int i=0;i<n;i++){
				int ls;
				cin>>ls;
				ans*=2;
				ans%=N;
			}
			cout<<ans%N<<endl;
		}	
	} 
	int ans=0;
	while(t--){
		cin>>n>>m;
		for(int i=0 ;i<n;i++){
			cin>>a[i].a1;
			a[i].bi=a[i].a1;
			a[i].ij=i;
			a[i].now=1;
		}
		for(int j=0;j<n;j++){
			sort(a,a+n,cmp);
			for(int i=j;i<n;i++){
				a[i].bi=a[i].a1;
				a[i].now=1;
				int xx=ans1();
				int me=ans2(0,m,0);
				if(xx==me) ans++;
				cout<<xx<<" "<<me<<endl;
				a[i].now=2;
				a[i].bi=a[i].a1/2;
				sort(a,a+n,cmp);
				xx=ans1();
				me=ans2(0,m,0); 
				if(xx==me) ans++;
				cout<<xx<<" "<<me<<endl;
			}
			ans%=N;
		}
		cout<<(ans%N)*2<<endl;
	}
	return 0;
} 
