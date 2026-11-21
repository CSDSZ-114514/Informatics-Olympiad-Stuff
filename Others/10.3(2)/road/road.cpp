#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct PT{
    long long x,y;
}pt[100005];
double dist(long long a,long long b){
    return sqrt((pt[a].x-pt[b].x)*(pt[a].x-pt[b].x)+(pt[a].y-pt[b].y)*(pt[a].y-pt[b].y));
}
struct ED{
    long long to;double dis;
};
vector<ED> ed[100005];
double d[100005];
bool vis[100005];
double prim(int s) {
	for(int i=0; i<=n; i++) {
		d[i] = 1e9;
	}
	d[s] = 0; 
	double sum = 0;
	for(int i=1; i<=n; i++) { 
		int u=0;
		for(int j=1; j<=n; j++) {
			if(!vis[j] && d[j] < d[u]) {
				u = j;
			}
		}
		vis[u] = 1; 
		sum += d[u]*1.0;
		for(ED t:ed[u]) {
			if(!vis[t.to] && d[t.to] > t.dis) { 
				d[t.to] = t.dis;
			}
		}
	}
	return sum;
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>pt[i].x>>pt[i].y;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ed[i].push_back({j,dist(i,j)});
            ed[j].push_back({i,dist(i,j)});
        }
    }
    for(int i=1;i<=m;i++){
        long long a,b;cin>>a>>b;
        ed[a].push_back({b,0});
        ed[b].push_back({a,0});
    }
    cout<<fixed<<setprecision(2)<<prim(1);
    return 0;
}