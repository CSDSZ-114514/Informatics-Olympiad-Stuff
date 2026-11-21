#include<bits/stdc++.h>
using namespace std;
long long T,n,k,q;
vector<long long> v[200005];
long long f[105][200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		memset(v,0,sizeof(v));
		memset(f,-1,sizeof(f));
		cin>>n>>k>>q;
		for(int z=1;z<=n;z++){
			long long l=0;cin>>l;
			for(int i=1;i<=l;i++){
				long long t;
				cin>>t;
				v[z].push_back(t);
			}
		}
		f[0][1]=0;
		for(int i=1;i<=100;i++){
			for(int j=1;j<=n;j++){
				long long cnt=0;
				for(int t:v[j]){
					if(cnt>0){
						if(f[i][t]==-1){
							f[i][t]=j;
						}else if(f[i][t]!=j){
							f[i][t]=0;
						}
						cnt--;
					}
					if(f[i-1][t]!=-1&&f[i-1][t]!=j){
						cnt=k-1;
					}
					
				}
			}
		}
		for(int i=1;i<=q;i++){
			long long r,c;
			cin>>r>>c;
			
			if(f[r][c]==-1){
				cout<<"0\n";
			}else{
				cout<<1<<"\n";
			}
		}
	}
}