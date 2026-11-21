#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,v[100005];
bool vis[100005];
struct ED{
    long long frm,mon;
};
vector<long long> ed[100005];
queue<ED>q;
int main(){
    cin>>n>>m>>a>>b;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=m;i++){
        long long x,y;cin>>x>>y;
        ed[x].push_back(y);
    }
	q.push({a,0});
	while(!q.empty()){
		long long uf=q.front().frm;
		long long um=q.front().mon;
		if(uf==b){
			cout<<um+v[b]-v[a];
			return 0;
		}
        q.pop();
		for(long long i:ed[uf]){
			if(!vis[i]){
				vis[i]=1;
				q.push({i,um+1});
			}
		}
	}
	cout<<"No solution";
    return 0;
}