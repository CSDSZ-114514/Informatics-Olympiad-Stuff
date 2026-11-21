#include<bits/stdc++.h>
using namespace std;
long long s[3005][10005],T;

int main(){
	cin>>T;
	while(T--){
		long long n,k,q,l,r,c;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(r==1){
				bool fa=false;
				for(int j=1;j<=n;j++){
					for(int z=2;z<=k;z++){
						if(s[j][z]==c){
							fa=true;
							break;
						}
					}
				}
				if(fa){
					cout<<1<<endl;
				}else{
					cout<<0<<endl;
				}
			}
		}
	}
}
