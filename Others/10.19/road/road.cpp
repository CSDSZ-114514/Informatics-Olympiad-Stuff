#include<bits/stdc++.h>
using namespace std;
long long n,d,sum;
long long v[100005],a[100005];
int main(){
            freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long lb=1,llb=1;double lastoil=0;
	while(lb<=n){
		lb++;
		if(a[lb]<a[llb]||lb==n){
			long long sumv=0;
			for(int i=llb;i<lb;i++){
				sumv+=v[i];
			}
			double needoil=ceil(1.0*sumv/d-lastoil);
			sum+=(a[llb]*(needoil));
			lastoil=needoil+lastoil-1.0*sumv/d;
			llb=lb;
		}
		
	}
	cout<<sum;
    return 0;
}