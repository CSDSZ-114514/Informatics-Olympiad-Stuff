# include<bits/stdc++.h>
using namespace std;
long long n,m,a[50100],w[50100],c,t,sum,cnt,d[50100];
long double b[50100];
bool f=true;
void printf(int k){
	sum=m;
	for(int i=1;i<=k;i++){
		d[i]=w[i];
	}
	for(int i=1;i<=k;i++){
		b[i]=a[i]*1.0/d[i];
	}
	for(int i=1;i<=k-1;i++){
		for(int j=1;j<=k-i;j++){
			if(b[j]<b[j+1]){
			long double zh=b[j+1];
			b[j+1]=b[j];
			b[j]=zh;
			long long zh1=a[j+1];
			a[j+1]=a[j];
			a[j]=zh1;
			zh1=d[j+1];
			d[j+1]=d[j];
			d[j]=zh1;
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(sum>=d[i]){
			sum-=d[i];
		}
	}
	if(sum==0){
		cnt++;
	}
}
void fun(int g,int p,int k){
	if(p>=3){
		return;
	}
	if(g==k){
		printf(k);
		return ;
	}
	if(p==1){
		w[g+1]=p;
		fun(g+1,p,k);
		w[g+1]=p+1;
		fun(g+1,p+1,k);
	}
	else if(p==2){
		w[g+1]=p-1;
		fun(g+1,p-1,k);
		w[g+1]=p;
		fun(g+1,p,k);
	}
}
int main(){
	
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	for(int e=1;e<=t;e++){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2){
				if(a[i]!=a[i-1]){
					f=false;
				}
			}
		}
		if(f==true){
			cnt=1;
			for(int i=1;i<=n;i++){
				cnt*=2;
			}
			cout<<cnt%998244353<<endl;
		}
		else{
			fun(0,1,n);
			cout<<cnt%998244353<<endl;
		}
		cnt=0;
	}
	
	
	return 0;
} 
