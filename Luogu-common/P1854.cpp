#include<bits/stdc++.h>
using namespace std;

int v,fx,f[1005][1005],as=-1e9,ab[1005][1005];
void showshowway(int x,int ans){
	if(x==0)return;
	int p=x;
	while (f[x][p]!=ans){
		p++;
	}
	showshowway(x-1,ans-ab[x][p]);
	cout<<p<<" ";
}
int main(){
	cin>>fx>>v;
	for(int i=1;i<=fx;i++){
		for(int j=1;j<=v;j++){
			cin>>ab[i][j];
		}
	}
	memset(f,128,sizeof(f));
	for(int i=0;i<=fx;i++){
		f[i][0]=0;
	}
	for(int i=1;i<=fx;i++){
		for(int j=i;j<=v;j++){
			for(int k=i-1;k<=j-1;k++){
				f[i][j]=max(f[i][j],f[i-1][k]+ab[i][j]);
			}
		}
	}
	for(int i=fx;i<=v;i++){
		as=max(as,f[fx][i]);
	}
	cout<<as<<endl;
	showshowway(fx,as);
}
