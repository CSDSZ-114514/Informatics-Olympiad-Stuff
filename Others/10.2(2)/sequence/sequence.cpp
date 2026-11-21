#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long rd[200005],val[200005],f[200005][15],ans;
vector<long long> e[200005];
queue<long long> q;
void toposort() {
	for(int i=1; i<=n; i++) {
        if(rd[i]==0){
            q.push(i);
        }
	}

	while(!q.empty()) {
		long long u = q.front();
        //cout<<u.frm<<" "<<u.cnt<<endl;
		q.pop();
		for(int v:e[u]) {
			rd[v]--; 
			if(rd[v] == 0){ 
				q.push(v);
			}
            for(int i=1;i<=val[v];i++){
                f[v][val[v]]=max(f[v][val[v]],f[u][i]+1);
            }
            for(int i=1;i<=10;i++){
                f[v][i]=max(f[v][i],f[u][i]);
            }
		}
	} 
} 
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>val[i];f[i][val[i]]=1;
    }
    for(int i=1;i<=m;i++){
        long long a,b;
        cin>>a>>b;
        e[a].push_back(b);
        rd[b]++;
    }
    toposort();
    for(int i=1;i<=10;i++){
        for(int j=1;j<=n;j++){
            ans=max(ans,f[j][i]);
        }
    }
    cout<<ans;
}