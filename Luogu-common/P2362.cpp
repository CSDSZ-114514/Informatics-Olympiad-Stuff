#include<bits/stdc++.h>
using namespace std;
int n,h[1005],m;
int fa[1005],f[1005];

int main(){
	cin>>m;
	for(int b=1;b<=m;b++){
		memset(f,0,sizeof(f));
		memset(fa,0,sizeof(fa));
		memset(h,0,sizeof(h));
		cin>>n;
		for(int i=1;i<=n;i++){
			f[i]=1;
			fa[i]=1;
		}
		
		for(int i=1;i<=n;i++){
			cin>>h[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(h[i]>=h[j]){
					if(f[i]<f[j]+1){
						f[i]=f[j]+1;
						fa[i]=fa[j];
					}else if(f[i]==f[j]+1){
						fa[i]+=fa[j];
					}
				}
			}
		}
//		cout<<endl<<endl;
//		for(int i=1;i<=n;i++){
//			printf("%d ",f[i]);
//		}cout<<endl;
//		for(int i=1;i<=n;i++){
//			printf("%d ",fa[i]);
//		}cout<<endl;
//		//cout<<f[n]<<" "<<fa[n]<<endl;
		int mx=0;
		for(int i=1;i<=n;i++){
			if(f[mx]<f[i]){
				mx=i;
			}
		}
		cout<<f[mx]<<" "<<fa[mx]<<endl;
	}
}
