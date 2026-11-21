#include<bits/stdc++.h>
using namespace std;
long long m,a[10005],b[10005],sg[10005];
long long getsg(long long u){
    if(sg[u]!=-1){
        return sg[u];
    }
    set<long long> p;
    for(int i=1;i<=m;i++){
        if((u-b[i])<0)break;
        p.insert(getsg(u-b[i]));
    }
    for(int i=0;;i++){
        if(p.count(i)==0){
            sg[u]=i;
            return sg[u];
        }
    }
}
int main(){
    long long n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    long long s=0;
    memset(sg,-1,sizeof(sg));
    for(int i=1;i<=n;i++){
        s^=getsg(a[i]);
    }
    
    cout<<(s!=0?"YES":"NO")<<endl;
    if(s!=0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(sg[a[i]-b[j]]==(sg[a[i]]^s)){cout<<i<<" "<<b[j]<<endl;return 0;}
            }
        }
    }
    
    return 0;
}