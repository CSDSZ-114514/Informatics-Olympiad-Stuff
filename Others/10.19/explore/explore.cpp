#include<bits/stdc++.h>
using namespace std;
long long f[1005][1005],n,m,mp[1005][1005],T,k,nx,ny,nd,ans;
bool isok(long long dx,long long dy){
	if(dx>=1&&dy>=1&&dx<=n&&dy<=m){
		if(mp[dx][dy]){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
void walk(){
	if(nd==0){
		long long dx=nx,dy=ny+1;
		if(isok(dx,dy)){
			nx=dx,ny=dy;
			f[dx][dy]=1;
		}else{
			nd=(nd+1)%4;
		}
	}else
	if(nd==1){
		long long dx=nx+1,dy=ny;
		if(isok(dx,dy)){
			nx=dx,ny=dy;
			f[dx][dy]=1;
		}else{
			nd=(nd+1)%4;
		}
	}else
	if(nd==2){
		long long dx=nx,dy=ny-1;
		if(isok(dx,dy)){
			nx=dx,ny=dy;
			f[dx][dy]=1;
		}else{
			nd=(nd+1)%4;
		}
	}else
	if(nd==3){
		long long dx=nx-1,dy=ny;
		if(isok(dx,dy)){
			nx=dx,ny=dy;
			f[dx][dy]=1;
		}else{
			nd=(nd+1)%4;
		}
	}
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(mp,0,sizeof(mp));
		ans=0;
		cin>>n>>m>>k;cin>>nx>>ny>>nd;
		string shr;
		for(int i=1;i<=n;i++){
			cin>>shr;
			//cout<<shr;
			for(int j=0;j<m;j++){
				if(shr[j]=='x'){
					mp[i][j+1]=0;
				}else{
					mp[i][j+1]=1;
				}
			}
		}

		
		f[nx][ny]=1;
		for(int i=1;i<=k;i++){
			walk();
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cout<<f[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=f[i][j];
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}