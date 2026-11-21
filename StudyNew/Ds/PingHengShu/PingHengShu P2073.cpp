#include<bits/stdc++.h>
using namespace std;
long long n;long long  w,c;
struct NODE{
    long long w,c;
    bool operator <(const NODE p) const{
        return c<p.c;
    }
};
set<NODE> s;
int main(){
    while(true){
        cin>>n;
        if(n==1)cin>>w>>c,s.insert({w,c});
        if(n==2&&!s.empty())s.erase(--s.end());
        if(n==3&&!s.empty())s.erase(s.begin());
        if(n==-1){
            long long ans=0,ans2=0;
            for(NODE t:s){
                ans+=t.c;
                ans2+=t.w;
            }
            cout<<ans2<<" "<<ans;
            return 0;
        }
    }
    return 0;
}