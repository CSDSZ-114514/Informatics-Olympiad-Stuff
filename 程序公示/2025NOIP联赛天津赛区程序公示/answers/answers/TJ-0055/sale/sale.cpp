#include<bits/stdc++.h>
using namespace std;
bool f1(int n,int *a1,int nn,int m){
	int w[n],a[n];
	float s[n];
	int i=0;
	for(int i=0;i<n;i++){
		w[i]=1;
	}
	while(nn>1){
		
		if(nn%2==1)w[i]=2;
		i++;
		nn=nn/2;
	}
	if(nn==1){
		w[i]=2;
	}
	for(int i=0;i<n;i++){
		s[i]=*(a1+i)/w[i];
		a[i]=*(a1+i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(s[j]<s[j+1]||(s[j]==s[j+1]&&a[j]<a[j+1])){
				int nnn=s[j+1],nnnn=w[j+1],nnnnn=a[j+1];
				s[j+1]=s[j];
				w[j+1]=w[j];
				a[j+1]=a[j];
				s[j]=nnn;
				w[j]=nnnn;
				a[j]=nnnnn;
			}
		}
	}
	int sum=0,sum1=0,m1=m;
	for(int i=0;i<n;i++){
		if(m>=w[i]){
			m=m-w[i];
			sum=sum+a[i];
		}
		if(m==0)break;
	}
	m=m1;
	for(int i=0;i<n;i++){
		if(m>=w[i]){
			m=m-w[i];
			sum1=sum1+a[i];
		}
		
		if(m==0)break;
		if(m<w[i]&&m==1){
			int aa=0;
			for(int j=i+1;j<n;j++){
				if(w[j]==1){
					aa=a[j];
					break;
				}
			}
			if(a[i]>=(a[i-1]+aa)){
				m=m-1;
				sum1=sum1-a[i-1];
				sum1=sum1+a[i];
			}
		}
		if(m==0)break;
		
	}
	if(sum>=sum1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int c=0;c<t;c++){
		int n,m;
		cin>>n>>m;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long sum=0;
		for(int i=0;i<(1<<n);i++){
			sum=sum+f1(n,&a[0],i,m);
		}
		cout<<sum%998244353<<endl;
	}
	return 0;
}
