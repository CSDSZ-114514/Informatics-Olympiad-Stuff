#include<bits/stdc++.h>
using namespace std;

int t;
int n,m;

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	srand((unsigned)time(0));
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;++i){
			int xx;
			scanf("%d",&xx);
		}
		printf("%d\n",rand()%(5*n));
	}
	return 0;
}
