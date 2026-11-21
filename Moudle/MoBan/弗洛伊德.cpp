#include<bits/stdc++.h>
using namespace std;
long long f[1005][1005],n,m,u,v,w;
int main(){
	cin>>n>>m;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		cin>>w;
		f[u][v]=min(f[u][v],w);
		f[v][u]=f[u][v];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
}

