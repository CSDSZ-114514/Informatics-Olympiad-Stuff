#include <bits/stdc++.h>
using namespace std;
using namespace std;
int a[1000005],p[1000005],f[1000005],cnt,n;
//艾筛
void  soei(){
	
}
//欧筛
void  soeo(){
	a[0]=1;a[1]=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			p[++cnt]=i;
			f[i]=1;//
		}
		for(int j=1;j<=cnt&&p[j]*i<=n;i++){
			a[p[j]*i]=1;
			f[p[j]*i] = f[i]+1;//
			if(i%p[j]==0){
				break;
			}
		}
	}
}
int main(){
	int N,M,ans=0;
	cin>>N>>M;
	n=M;
	soeo();
	for(int i=M;i>=N;i--){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
} 
