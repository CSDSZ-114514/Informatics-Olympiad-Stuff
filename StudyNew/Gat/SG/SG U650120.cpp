#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<long long> e[100005];
long long sg[100005];
long long getsg(long long u){
    if(sg[u]!=-1){
        return sg[u];
    }
    set<long long> p;
    for(int v:e[u]){
        p.insert(getsg(v));
    }
    for(int i=0;;i++){
        if(p.count(i)==0){
            sg[u]=i;
            return i;
        }
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        long long a,b;
        cin>>a>>b;
        e[a].push_back(b);
    }
    memset(sg,-1,sizeof(sg));
    long long s=0;
    for(int i=1;i<=k;i++){
        long long p;cin>>p;
        s^=getsg(p);
    }
    if(s!=0){
        cout<<"win";
    }
    else{
        cout<<"lose";
    }
    return 0;
}