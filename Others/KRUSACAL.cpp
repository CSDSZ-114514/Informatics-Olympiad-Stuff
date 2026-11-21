#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct ED{
    long long u,v,w;
};
bool cmp(ED x,ED y){
    return x.w<y.w;
}
ED e[120005];
long long fa[30005];
long long find(long long a){
    if(fa[a]==a){
        return a;
    }else{
        return fa[a]=find(fa[a]);
    }
}
long long heb(long long a,long long b){
    fa[find(a)]=find(b);
}
long long kruscal(){
    long long sum=0,cnt=0;
    sort(e+1,e+1+m,cmp);
    // for(int i=1;i<=2*m;i++){
    //     cout<<e[i].w<<endl;
    // }
    for(int i=1;i<=m;i++){
        if(find(e[i].u)!=find(e[i].v)){
            sum+=e[i].w;cnt++;
            heb(e[i].u,e[i].v);
        }
    }
    //cout<<cnt;
    if(cnt<n-1){
        return -1;
    }else{
        return sum;
    }
}
int main(){
    long long ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        long long x,y,z;
        cin>>x>>y>>z;
        e[i]={x,y,z};
    }
    ans=kruscal();
    if(ans==-1)cout<<"orz";
    else cout<<ans;
    return 0;
}