#include<bits/stdc++.h>
using namespace std;
long long L,R,ans,p[1000005];
long long cal(long long p){
    return R/p-(L-1)/p;
}
long long q=0;
void dfs(long long x,long long t,long long cnt){
    if(x>q){
        if(cnt==0){
            return ;
        }else if(cnt%2==1){
            ans+=cal(t);
        }else{
            ans-=cal(t);
        }
        return ;
    }
    dfs(x+1,t,cnt);
    if((unsigned long long)t*p[x]/__gcd(t,p[x])<=R){
        dfs(x+1,(unsigned long long)t*p[x]/__gcd(t,p[x]),cnt+1);
    }
}
bool cmp(long long x,long long y){
    return x>y;
}
void dfs2(long long x){
    if(x!=0)p[++q]=x;
    if(x*10+6<=R)dfs2(x*10+6);
    if(x*10+8<=R)dfs2(x*10+8);
}
int main(){
    cin>>L>>R;
    dfs2(0);
    sort(p+1,p+1+q,cmp);
    dfs(1,1,0);
    cout<<ans;
}