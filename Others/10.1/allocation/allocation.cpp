#include<bits/stdc++.h>
using namespace std;
long long n;
struct BC{
	long long bw,cw;
};
bool cmp(BC x,BC y){
	return max(x.bw,x.cw)<max(y.bw,y.cw);
}
BC bc[200005];long long lstbn[200005],lstcn[200005];
int main(){
	freopen("allocation.in","r",stdin);
	freopen("allocation.out","w",stdout);
	cin>>n;
	for(int i=1;i<=2*n;i++){
		cin>>bc[i].bw;
	}
	for(int i=1;i<=2*n;i++){
		cin>>bc[i].cw;
	}
	sort(bc+1,bc+1+2*n,cmp);
//	for(int i=2*n;i>=1;i--){
//		lstbn[i]=lstbn[i+1];
//		lstcn[i]=lstcn[i+1];
//		if(bc[i].bw>bc[i].cw){
//			lstbn[i]++;
//		}
//		if(bc[i].bw<bc[i].cw){
//			lstcn[i]
//		}
//	}
	long long bn=0,cn=0,ans=0;
	for(int i=1;i<=2*n;i++){
		if(bn<n&&bc[i].cw<bc[i].bw){
			ans+=bc[i].bw;
			bn++;
			continue;
		}
		if(bn==n){
			ans+=bc[i].cw;
			cn++;
			continue;
		}
		if(cn<n&&bc[i].cw>bc[i].bw){
			ans+=bc[i].cw;
			cn++;
			continue;
		}
		if(cn==n){
			ans+=bc[i].bw;
			bn++;
			continue;
		}
		if(bc[i].cw==bc[i].bw){
			ans+=bc[i].bw;
			continue;
		}
	}
	cout<<ans;
}
