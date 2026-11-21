#include<bits/stdc++.h>
using namespace std;
long long T;
unordered_map< long long , long long > mp;
long long cd[100005];
bool flag=false;
long long ms=1e9+7;
long long qpow(long long a,long long b,long long m){
    long long ans=1;
    while(b>0){
        if(b%2==1){
            ans=ans*a%m;
        }
        b/=2;
        a=a*a%m;
    }
    return ans;
}
int main(){
    cin>>T;
    while(T--){
        mp.clear();
        memset(cd,0,sizeof(cd));
        long long ans=1;flag=false;
        long long n,m,v;cin>>n>>m>>v;

        for(int i=1;i<=m;i++){
            long long c=0,d=0;
            cin>>c>>d;cd[i]=c;
            if(mp[c]&&mp[c]!=d) flag=true;
            mp[c]=d;
        }
        if(flag){
            cout<<0<<endl;
            continue;
        }
        sort(cd+1,cd+1+m);
        for(int i=2;i<=m;i++){
            if(cd[i]==cd[i-1])continue;
            ans=ans*((qpow(v,2*cd[i]-2*cd[i-1],ms)-qpow(v,(cd[i]-cd[i-1]-1),ms)*(v-1)%ms+ms)%ms)%ms;
        }
        ans=ans*(qpow(v,2*cd[1]-2,ms))%ms;
        ans=ans*qpow(v,2*n-2*cd[m],ms)%ms;
        cout<<(ans+ms)%ms<<endl;
    }
    return 0;
}