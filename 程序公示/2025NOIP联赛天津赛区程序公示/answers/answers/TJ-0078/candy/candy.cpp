#include<bits/stdc++.h>
using namespace std;
long long n,p,m,k[2][100001]={},a1,a2,q=0,b[100001],daan,qq;
struct kk{
	long long v;
}a[100001];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a1>>a2;
		
		b[i]=a1;
		a[i].v=a2+a1;
		
		
	}
	sort(b+1,b+1+n,cmp);
	for(long long i=1;i<=n;i++){
//		for(int j=0;j<=m;j++){
//			if(j>=a[i].v){
//				
//				k[i][j]=max(max(k[i-1][j],k[i][j-a[i].v]+2),k[i-1][j-a[i].v]+2);
//				
//			}else{
//				k[i][j]=k[i-1][j];
//			}
//		}
		for(long long j=0;j<=m;j++){
			if(j>=a[i].v){
				
				k[i%2][j]=max(max(k[(i-1)%2][j],k[i%2][j-a[i].v]+2),k[(i-1)%2][j-a[i].v]+2);
				
			}else{
				k[i%2][j]=k[(i-1)%2][j];
			}
		}
	}
	
	for(long long i=1;i<=n;i++){
		 //k[n][m-b[i]]+1>=k[n][m] && 
		if(m>=0 && m-b[i]-qq>=0){
			daan=max(k[n%2][m-qq]+q,daan);
			qq+=b[i];
			q++;
			daan=max(k[n%2][m-qq]+q,daan);
//			cout<<m-qq<<endl;
//			cout<<k[n][m-qq]<<endl;
//			cout<<k[n][m-qq]+q<<endl;
		}
		
	}
//	daan=k[n][m];
//	for(int i=1;i<=n;i++){
//		if(m>=0){
//			m-=b[i];
//			q++;
//			daan=max(k[n][m]+q,daan);
//		}
//	}
//	for(int i=0;i<=m;i++){
//		cout<<k[n][i]<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<endl;
//	}
	//cout<<q;
	cout<<daan;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
