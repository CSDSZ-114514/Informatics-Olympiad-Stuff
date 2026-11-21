#include<bits/stdc++.h>
using namespace std;
long long n, m;
struct ed{
    long long v;
};
vector<ed> e[2000005];
long long scc[2000005], dfn[2000005], low[2000005], siz[2000005], cnt, tot;
stack<long long> s;
void tj(long long u){
    dfn[u]=++tot;
    low[u] = tot;
    s.push(u);
    for(auto t:e[u]){
        if(!dfn[t.v]){
            tj(t.v);
            low[u] = min(low[u], low[t.v]);
        }else if(!scc[t.v]){
            low[u] = min(low[u], dfn[t.v]);
        }
    }
    if(dfn[u]==low[u]){
        cnt++;
        while(!s.empty()){
            long long t = s.top();
            s.pop();
            scc[t] = cnt;
            siz[cnt]++;
            if(t==u){
                break;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        e[a+!b*n].push_back({c+d*n}); 
		e[c+!d*n].push_back({a+b*n}); 
    }
    for(int i=1; i<=2*n; i++) {
		if(!dfn[i]) {
			tj(i);
		}
	}
    for(int i=1; i<=n; i++) {
		if(scc[i] == scc[i+n]) {  
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
    cout<<"POSSIBLE"<<endl;
	for(int i=1; i<=n; i++) {
		cout<< (scc[i]>scc[i+n]?1:0)<<" "; 
	}
}