#include<bits/stdc++.h>
using namespace std;
long long n,m;bool f[10005][10005];
vector<int> ed[10005];
void floyd() {
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				f[i][j]=(f[i][j])||(f[i][k]&&f[k][j]); 
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		f[a][b]=1;
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	floyd();
	long long cnt=0;
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=1;j<=n;j++){
			
			if((f[i][j]||f[j][i])&&i!=j){
				num++;
			}
		}
		if(num==n-1){
			cnt++;
		}
	}
	cout<<cnt;
}
