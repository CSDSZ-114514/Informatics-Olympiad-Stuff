#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 8005;
int n,m,fa[N],mex[N],ans=0,t,num[N],flags[N];
vector<int> edge[N],child[N];

void dfs(int x){
	num[x] = 1;
	int flag = 1;
	for(auto y:edge[x]){
		dfs(y);
		if(num[y] != 1){
			flag = 0;
		}
	}for(auto y:edge[x]){
		if(flag){
			num[x] += num[y];
		}else{
			num[x] = max(num[x],num[y]+1);
		}
	}
}void dfss(int x){
	if(!x){
		return ;
	}
	int ma = 0,maid = 0;
	for(auto y:edge[x]){
		if(num[y] > ma){
			ma = num[y];
			maid = y;
		}
	}ans += num[x];
	dfss(maid); 
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		
		for(int i = 2;i <= n;i++){
			int x;
			scanf("%d",&x);
			fa[i] = x;
			child[x].push_back(i);
			edge[x].push_back(i);
		}
		dfs(1);
		for(int i = 1;i <= n;i++){
			int obs = 0;
			for(auto x:child[i]){
				if(edge[x].empty()){
					obs++;
				}
			}if(obs > 1){
				ans -= obs-1;
			}
		}
		for(int i = 1;i <= n;i++){
			ans += num[i];
			
			num[i] = 0;
			fa[i] = 0;
			child[i].clear();
			edge[i].clear();
		}cout << ans << endl;
		
		ans = 0;
	}


}/*#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 8005;
int n,m,fa[N],mex[N],ans=0,t,num[N],flags[N];
vector<int> edge[N],child[N];
void dfs(int x){
	num[x] = 1;
	bool flag = 1;
	for(auto y:edge[x]){
		dfs(y);
	}for(auto y:edge[x]){
		num[x] += num[y];
	}
}
void dfs(int x,bool flag){
	num[x] = 1;
	for(auto y:edge[x]){
		dfs(y);
	}for(auto y:edge[x]){
		if(flag){
			num[x] += num[y];
		}else{
			num[x] = max(num[x],num[y]+1);
		}
	}
}void dfss(int x){
	if(!x){
		return ;
	}
	int ma = 0,maid = 0;
	for(auto y:edge[x]){
		if(num[y] > ma){
			ma = num[y];
			maid = y;
		}
	}ans += num[x];
	dfss(maid); 
}
int main(){
	freopen("tree1.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		
		for(int i = 2;i <= n;i++){
			int x;
			scanf("%d",&x);
			fa[i] = x;
			child[x].push_back(i);
			edge[x].push_back(i);
		}
		dfs(1);
		dfss(1);
		for(int i = 1;i <= n;i++){
			num[i] = 0;
			fa[i] = 0;
			child[i].clear();
			edge[i].clear();
		}cout << ans << endl;
		
		ans = 0;
	}

}*/
