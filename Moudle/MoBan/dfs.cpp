#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
//#include<bits/stdc++.h>
#include<queue> 
#include<map> 
#define LL long long
using namespace std;
int g[1005][1005],f[1005],n,m;
void dfs(int x){
	for(int i=1;i<=n;i++){
		if(g[x][i]==1&&f[i]==0){
			f[i]=1;
			dfs(i);
		}
	}
}
int main(){
	int a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		g[a][b]=1;
		g[b][a]=1;
	}
	f[1]=1;
	dfs(1);
	if(f[n]==1){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
