#include<bits/stdc++.h>
using namespace std;
int n,m,x,f[505][505][305];
int mp[1005][1005];
const int que=int('?'-'0');
int main(){
	long long t;
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(mp,0,sizeof(mp));
		cin>>n>>m>>x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char a;
				cin>>a;
				mp[i][j]=int(a-'0');
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=0;k<=x;k++){
					if(mp[i][j]==que){
						if(k>0){
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+1);
							f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+1);
						}
						f[i][j][k]=max(f[i][j][k],f[i-1][j][k]);
						f[i][j][k]=max(f[i][j][k],f[i][j-1][k]);
					}else{
						f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+mp[i][j]);
						f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+mp[i][j]);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=x;i++){
			ans=max(ans,f[n][m][i]);
		}
		cout<<ans<<endl;
	}
}
