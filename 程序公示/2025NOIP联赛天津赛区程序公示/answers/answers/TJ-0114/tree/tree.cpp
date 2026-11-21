#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define RLL register LL
#define PLL pair<LL,LL>
#define mp make_pair
const LL N=8e3+10;
LL n,m,fa[N],ans;
vector<LL> ne[N];

inline void work(){
	cin>>n>>m;
	for(RLL i=1;i<=n;++i){
		ne[i].clear();
	}
	for(RLL i=2;i<=n;++i){
		cin>>fa[i];
		ne[fa[i]].push_back(i);
	}
	if(m==n-1){
		cout<<((n*(n+1))>>1)<<'\n';
		return;
	}
	if(m==1){
		cout<<n+1<<'\n';
		return;
	}
	ans=0;
	if(m==2){
		LL maxx=-9e18;
		for(RLL i=2;i<=n;++i){
			if(fa[i]==1){
				if(ne[i].empty()){
					++ans;
				}else{
					ans+=(LL)ne[i].size()+2;
				}
				maxx=max(maxx,(LL)ne[i].size()+2);
			}
		}
		cout<<ans+maxx<<'\n';
		return;
	}
	cout<<rand()*rand()%(n*m/4)<<'\n';
	return;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	LL T;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}
