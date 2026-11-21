#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long T;
bool pp[100005];
int main(){
	cin>>T;
	while(T--){
		memset(pp,0,sizeof(pp));
		cin>>n>>m;
		long long ls=0;bool flg=true,flg2=true;
		for(int i=1;i<=m;i++){
			long long o,p;cin>>o>>p;
			if(o==1)pp[p]=1;
			else {
				ls=p;
			}
			for(int i=1;i<=n;i++){
				
			}
			if(pp[ls]){
				cout<<i<<endl;
				flg=false;
			}
		}
		if(flg){
			cout<<-1<<endl;
		}
	}	
	return 0;
} 
