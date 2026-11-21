#include <iostream>
#include <vector>
#include <cstdio> 
using namespace std;
int T;
int n,m;
int p[8010];
bool vis[8010];
int d[8010];
vector<int> g[8010];//jiedian
vector<int> dfn;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		d[1]=0;
		for(int i=2;i<=n;i++){
			cin>>p[i];
			g[p[i]].push_back(i);
		}
		cout<<2*n-1<<endl;
	}
	return 0;
} 
