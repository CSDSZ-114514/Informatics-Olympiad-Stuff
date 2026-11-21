#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
ull n,m,c,k,tem,vic[10000005],p,q,cnt=0,d[10000005];
int main(){
	cin>>n>>m>>c>>k;
	for(ull i=1;i<=n;i++){
		cin>>tem;
		for(ull j=0;j<=k-1;j++){
			vic[j]|=tem>>j&1;
		}
	}
	for(ull i=1;i<=m;i++){
		cin>>p>>q;
		if(vic[p]==0&&d[p]==0){
			d[p]=1;
			cnt++;
		}
	}
	if(k-cnt==64){
		if(n==0){
			cout<<"18446744073709551616";
		}else{
			cout<<(1ull<<63)-n+(1ull<<63);
		}
	}else{
		cout<<(1ull<<(k-cnt))-n;
	}
}
