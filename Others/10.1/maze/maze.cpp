#include<bits/stdc++.h>
using namespace std;
long long a[1605][1605];bool flag=false;long long visx[1005][1005],visy[1005][1005],visxy[1005][1005];
int dx[5]={1,0,-1,0},dy[5]={0,1,0,-1};
long long n,m,sx,sy;
void dfs(long long x,long long y,long long modx,long long mody){
	if(flag){
		return;
	}else{
		if(visxy[modx][mody]&& (visx[modx][mody]!=x || visy[modx][mody]!=y)) {
			flag = 1;
			return;
		}
		visx[modx][mody]=x, visy[modx][mody]=y, visxy[modx][mody]= 1;
		for(int i=0;i<4;i++){
			long long tx=x+dx[i];long long ty=y+dy[i];
			long long tmodx=(modx+dx[i]+n)%n;long long tmody=(mody+dy[i]+m)%m;
			if(!a[tmodx][tmody]){
				if(visx[tmodx][tmody]!=tx || visy[tmodx][tmody]!=ty || !visxy[tmodx][tmody]){
					dfs( tx, ty,tmodx, tmody);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdin);
	while(cin>>n>>m){
		flag=false;
		memset(a,0,sizeof(a));
		memset(visx,0,sizeof(visx));
		memset(visy,0,sizeof(visy));
		memset(visxy,0,sizeof(visxy));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='#'){
					a[i][j]=1;
				}else if(c=='S'){
					sx=i;sy=j;
				}
			}
		}
		dfs(sx,sy,sx,sy);
		if(flag){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
	return 0;
}
