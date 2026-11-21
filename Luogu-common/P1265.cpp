#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+5;
long long n;
struct cit{
    long long x,y;
}c[N];
double dis(long long a,long long b){
    return sqrt(pow(c[a].x*1.0-c[b].x*1.0,2.0)+pow(c[a].y*1.0-c[b].y*1.0,2.0));
}

double d[N];bool vis[N];
double prim(long long s){
    for(int i=0;i<=n;i++){
        d[i]=INT_MAX;
    }
    d[s]=0;//vis[s]=1;
    double sum=0;
    for(int i=1;i<=n;i++){
        long long u=0;
        for(int j=1;j<=n;j++){
            if(d[j]<d[u]&&!vis[j]){
                u=j;
            }
        }
        vis[u]=1;
        sum+=d[u];
        for(int j=1;j<=n;j++){
            if(dis(u,j)<d[j]&&!vis[j]){
                d[j]=dis(u,j);
            }
        }
    }
    return sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i].x>>c[i].y;
    }
    cout<<fixed<<setprecision(2)<<prim(1);
    return 0;
}