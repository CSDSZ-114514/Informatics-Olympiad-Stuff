#include<bits/stdc++.h>
using namespace std;
long long n,k,p,r,rd[100005],ds1[100005];
bool vis[100005];
struct PR{
    long long nu,ds;
};

vector<long long> ed[100005];
void toposort(){
    queue<PR> q;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            q.push({i,1});
        }
    }
    while(!q.empty()){
        long long un=q.front().nu;
        long long ud=q.front().ds;
        if(un == k){
            cout<<ud;
		}
        q.pop();
        for(long long t:ed[un]){
            rd[t]--;
            ds1[t]=max(ds1[t],ud+1);
            
            if(rd[t]==0){
                q.push({t,ud+1});
            }
        }
    }
}
int main(){
    cin>>n>>k>>p;
    for(int i=1;i<=p;i++){
        long long tp;cin>>tp;vis[tp]=1;    
    }
    cin>>r;
    for(int i=1;i<=r;i++){
        long long v,s,a;cin>>v>>s;
        for(int j=1;j<=s;j++){
            cin>>a;
            ed[a].push_back(s);
            
            rd[s]++;
        }
    }
    memset(ds1,127,sizeof(ds1));
    toposort();
    cout<<(ds1[k]>1000000) ? -1 : ds1[k];

    return 0;
}