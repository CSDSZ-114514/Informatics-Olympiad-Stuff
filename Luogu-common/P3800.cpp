#include<bits/stdc++.h>
using namespace std;
long long  n,m,k,t;
long long a[4005][4005];
long long f[4005][4005];
deque <long long> q;
int main(){
	cin>>n>>m>>k>>t;
	for(int i=1;i<=k;i++){
		long long x,y;
		cin>>x>>y;
		cin>>a[x][y];
	}
	for(int i=1;i<=n;i++){
		q.clear();
		for(int j=1;j<=m;j++){
			if(j==1){
				for(int k=1;k<j+t;k++){
					if(k<=m){
						while(!q.empty()&&f[i-1][k]>f[i-1][q.back()]){
							q.pop_back();
						}
						q.push_back(k);
					}
				}
			}
			if(j+t<=m){
				while(!q.empty()&&f[i-1][j+t]>f[i-1][q.back()]){
					q.pop_back();
				}
				q.push_back(j+t);
				
			}
			if(q.front()<j-t){
				q.pop_front();
			}
			f[i][j]=f[i-1][q.front()]+a[i][j];
			
//			for(int z=max((long long)1,j-t);z<=min(m,j+t);z++){
//				f[i][j]=max(f[i-1][z]+a[i][j],f[i][j]);
//			}
		}
	}
	long long ans=-1e9;
	for(int i=1;i<=m;i++){
		ans=max(ans,f[n][i]);
	}
	cout<<ans;
	return 0;
}
