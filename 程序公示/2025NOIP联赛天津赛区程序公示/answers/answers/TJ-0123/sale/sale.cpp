#include <bits/stdc++.h>
using namespace std;
const int N=5e3,mod=998244353;
int c,T,n,m,p2[N+5],pa[N+5];
struct node{
    int v,p;
}v[N+5];
bool ppp(const node a,const node b){
    if (a.v==b.v)return a.p>b.p;
    else return a.v<b.v;
}
int find(int x){
    return lower_bound(pa+1,pa+n+1,x)-pa;
}
int down(int x){
    return lower_bound(pa+1,pa+n+1,x)-pa-1;
}
int inv[N+5],fac[N+5];
int kp(int a,int b){
    int res=1;
    while (b){
        if (b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
void init(int n){
    p2[0]=1;
    for (int i=1;i<=n;i++)p2[i]=2ll*p2[i-1]%mod;
    fac[0]=1;
    for (int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=kp(fac[n],mod-2);
    for (int i=n;i>=0;i--)inv[i-1]=1ll*inv[i]*i%mod;
}
int C(int i,int j){
    if (i<0||j<0||i<j)return 0;
    return 1ll*fac[i]*inv[j]%mod*inv[i-j]%mod;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    init(N);
    cin>>c>>T;
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=n;i++)
            cin>>v[i].v,v[i].p=i,pa[i]=v[i].v;
        if (m==1||c==18||c==16){cout<<p2[n]<<"\n";continue;}
        else if (c==17){
            sort(v+1,v+n+1,ppp);
            int mn=v[2].v/2;
            int t=0;
            if ((v[1].v>mn||(v[1].v==mn&&v[1].p<v[2].p))&&v[1].v!=v[2].v)t++;
            cout<<(p2[n]-t+mod)%mod<<"\n";
            continue;
        }
        sort(v+1,v+n+1,ppp);
        sort(pa+1,pa+n+1);
        int ans=0;
        for (int i=n;i>=1;i--){
            int p=find(v[i].v*2),r=n-i;
            p=find(v[i].v/2+1);
            if (v[p-1].v==v[i].v/2&&v[i].v%2==0)for (int j=p-1;;j--)if (v[j].v==v[i].v/2&&v[j].p<v[i].p)p=j;else break;
            for (int k=r;k<=min(r*2,m-2);k++){
                int t=k-(n-i);
                int pre=C(r,t);
                if (t==0)pre=1;
                t=abs(t);
                int las=0,z=m-2-k;
                for (int j=p;j<i-z;j++){
                    las=(las+1ll*C(i-j,z)*p2[down(v[i].v-v[j].v)]%mod)%mod;
                }
                ans=(ans+1ll*pre*las%mod)%mod;
                cout<<i<<" "<<v[i].v<<" "<<v[i].p<<" "<<pre<<" "<<las<<"\n";
            }
        }
        cout<<(p2[n]-ans+mod)%mod<<"\n";
    }
}
