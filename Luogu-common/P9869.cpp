#include<bits/stdc++.h>
using namespace std;
const long long T=1e5+1,F=-1e5-1,U=0,MX=1e5+5;
long long c,t;
map<long long ,long long> mp;
long long fa[MX];
long long find(long long x){
    if(x==T||x==F||x==U){
        return x;
    }
    if(mp[-x]){
        return U;
    }
    if(mp[x]){
        return x;
    }
    mp[x]=1;
    if(x<0){
        return find(-fa[-x]);
    }else{
        return fa[x]=find(fa[x]);
    }
}
int main(){
    cin>>c>>t;
    while(t--){
        memset(fa,0,sizeof(fa));
        long long n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            char v;cin>>v;
            long long a;cin>>a;
            if(v=='T'){
                fa[a]=T;
            }else if(v=='F'){
                fa[a]=F;
            }else if(v=='U'){
                fa[a]=U;
            }else if(v=='+'){
                long long b;cin>>b;
                fa[a]=fa[b];
            }else{
                long long b;cin>>b;
                fa[a]=-1*fa[b];
            }
        }
        for(int i=1;i<=n;i++){
            mp.clear();
            if(find(i)==U){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}