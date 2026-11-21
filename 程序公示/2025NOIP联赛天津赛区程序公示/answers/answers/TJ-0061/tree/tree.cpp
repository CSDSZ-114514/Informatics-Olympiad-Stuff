#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int N=8010;
int T;
int n,m;
int maxn[N];
struct point{
    int f;
    int h;
    int cnt=1;
    int s[N];
    int t;
}p[N];

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        //*********************
        int hmax=0;
        scanf("%d%d",&n,&m);
        p[1].h=0;
        p[1].cnt=1;
        p[1].t=0;
        p[1].f=1;
        for(int i=2;i<=n;i++){
            scanf("%d",&p[i].f);
            p[i].h=0;
            p[i].cnt=1;
            p[i].t=0;
            p[p[i].f].s[p[p[i].f].t++]=i;
        }
        for(int k=1;k<=m;k++)
            for(int i=1;i<=n;i++){
                int c=1;
                for(int j=0;j<p[i].t;j++){
                    p[p[i].s[j]].h=p[i].h+1;
                    hmax=max(hmax,p[p[i].s[j]].h);
                    c+=p[p[i].s[j]].cnt;
                    p[i].cnt=c;
                }
            }
        for(int i=0;i<=hmax;i++)
            maxn[i]=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(maxn[p[i].h]<p[i].cnt){
                ans-=maxn[p[i].h];
                maxn[p[i].h]=p[i].cnt;
                ans+=maxn[p[i].h];
            }
        }cout<<ans<<'\n';
        //*********************
    }
    return 0;
}//POINTS.!PLEASE.