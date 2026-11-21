#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout); 
	long long m;
	int n;
	cin>>n>>m;
	int a[100009],b[100009];
	long long minn=1e9,su;
    for(int i=0;i<n;i++){
    	scanf("%d%d",&a[i],&b[i]);
    	su=a[i]+b[i];
        minn=min(minn,su);
	}
	sort(a,a+n);
	long long maxn=m/minn;
	maxn*=2;
//	cout<<maxn<<endl;
	long long sum=0;
	long long k;
	long long cu=0;
	for(int i=0;i<n;i++){
	   sum+=a[i];
	   k=i+1;
	   cu=(m-sum)/minn;
	   cu*=2;
//	   cout<<k<<' '<<cu<<endl;
	   maxn=max(maxn,k+cu);
	}
	cout<<maxn;
	return 0;
}
