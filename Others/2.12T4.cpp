#include<bits/stdc++.h>
using namespace std;
long long n,a,d,b[1000005];
long long t[1000005];
long long ltfl[1000005],cnt,sum[1000005];
queue<long long> q;
void bfs(){
    for(int i=1;i<=n-1;i++){
        if(t[i]>0&&ltfl[i]==0){
            cnt++;ltfl[i]=cnt;
            long long s=0;
            q.push(i);
            while(!q.empty()){
                long long u=q.front();q.pop();
                s+=t[u];
                for(int dx=-2;dx<=2;dx++){
                    long long v=u+dx;
                    if(v>=1&&v<=n-1&&t[v]>0&&ltfl[v]==0){
                        ltfl[v]=cnt;
                        q.push(v);
                    }
                }
            }
            sum[cnt]=s;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin>>n>>a>>d;
    for(int i=1;i<n;i++){
        cin>>b[i];
        t[i]=max(0LL,(b[i]-2)/(2*d));
    }
    bfs();
    long long ans=0;
    if(t[a]>0){
        ans=sum[ltfl[a]];
    }else{
        for(int dx=-2;dx<=2;dx++){
            long long v=a+dx;
            if(v>=1&&v<=n-1&&t[v]>0){
                ans=max(ans,sum[ltfl[v]]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}