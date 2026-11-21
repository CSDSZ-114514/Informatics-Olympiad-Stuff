#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ed[10005];


int dfn[10005],low[10005],scc[10005],csc[10005],tot,cnt;
stack<int> s;
void tarjan(int u){
	dfn[u]=++tot;
	low[u]=tot;
	s.push(u);
	for(int v:ed[u]){
		if(dfn[v]==0){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(scc[v]==0){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		cnt++;
		while(true){
			int q=s.top();
			s.pop();
			scc[q]=cnt;
			csc[cnt]++;
			if(q==u){
				break;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		ed[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]==0){
			tarjan(i);
		}
	}
	int sum=0;
	for(int i=1;i<=cnt;i++){
		if(csc[i]!=1){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
