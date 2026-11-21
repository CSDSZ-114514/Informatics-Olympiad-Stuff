#include<bits/stdc++.h>
using namespace std;
struct youhui{
	int ti,pr;
}yh[100005];
long long n,pz,tick,ways,lwsp,usm;bool alu;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ways;cin>>pz>>tick;
		if(ways==1){
			alu=true;
			for(int j=max(i-45,0);j<=i;j++){
				if(tick-yh[j].ti<=45&&yh[j].pr>=pz){
					yh[j].pr=0;
					
					alu=false;
					break;
				}
			}
			if(alu){
				usm+=pz;
			}
		}
		if(ways==0){
			yh[i].pr=pz;
			yh[i].ti=tick;
			usm+=pz;
		}
	}
	cout<<usm;
}
