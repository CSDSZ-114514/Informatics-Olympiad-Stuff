#include<bits/stdc++.h>
using namespace std;
int main(){
    long long T;cin>>T;
    
    while(T--){
        long long n,m;
        cin>>n>>m;long long k=0;
        unordered_map<long long ,long long> mp;
        long long sum=0;
        for(int i=0;i<n;i++){
            long long x;cin>>x;
            mp[x]++;sum+=x;k=mp[x];
        }
        
        for(auto& p:mp){
            k=__gcd(k,p.second);
        }
        int res=0;
        for(int i=1;i<=m;i++){
            long long s=n/(__gcd(1LL*i,1LL*n));
            if(k%s||(1LL*i*sum)%n)continue;
            res++;
        }
        cout<<res<<endl;
    }
}