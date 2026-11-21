#include<bits/stdc++.h>
using namespace std;
int n,q,a[1005],tl,tn,sml;

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>tl>>tn;
		sml=1e9;
		for(int j=1;j<=n;j++){
			if(a[j]%int(pow(10,tl))==tn){
				sml=min(sml,a[j]);
			}
		}
		if(sml!=1e9){
			cout<<sml<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
