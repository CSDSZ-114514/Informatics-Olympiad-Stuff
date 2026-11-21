#include<bits/stdc++.h>
using namespace std;
long long n,v,f[1005][1005];
map<long long,string> nam;
map<string,long long> nams;
vector<long long> e[1000005];
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>nam[i];
		nams[nam[i]]=i;
	}
	for(int i=1;i<=v;i++){
		string xx,yy;cin>>xx>>yy;
		long long x,y;
		x=nams[xx];y=nams[yy];
		if(y<x)swap(x,y);
		e[x].push_back(y);
	}
	//for(int i=1;i<=n;i++)for(auto p:e[i])cout<<i<<" "<<p<<endl;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=-1;
	for(auto t:e[1]){
		f[1][t]=2;
	}
	for(int j=2;j<=n;j++){
		for(int i=1;i<j;i++){
			if(f[i][j]==-1)continue;
			for(auto k:e[i]){
				if(k>j){
					f[j][k]=max(f[j][k],f[i][j]+1);
				}
			}
			for(auto k:e[j]){
				if(k>j){
					f[i][k]=max(f[i][k],f[i][j]+1);
				}
			}
		}
	}
	long long ans=1 ;
	for(int i=1;i<n;i++){
    	for(auto k:e[i]){
        	if(k==n){
            	ans=max(ans,f[i][n]);
            	break;
        	}
    	}
	}
	cout<<ans;
	return 0;
}
