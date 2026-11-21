#include<bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long LL;
const int N=1e5+5;
LL x[N],y[N];
int n;
LL m;
namespace TX{
    struct Item{
        double val;
        //2:maiduoci  lianggedabao
        //1:maiyici
        int type;
        int id;
        bool operator<(const Item& o)const{
            if(val!=o.val)
                return val<o.val;
            else
                type>o.type;
        }
    }e[N<<1];
    int cnt=0;
    bool cho1[N];
    priority_queue<LL>q;
    LL cal(){
        LL nowsp=0,res=0;
        for(int i=1;i<=cnt;++i){
            if(e[i].type==1){
                if(e[i].val+nowsp<=m){
                    ++res,nowsp+=e[i].val;
                    cho1[e[i].id]=1;
                    q.push(e[i].val);
                }
                else
                    break;
            }
            else{//type=2
                double sp=e[i].val*2;
                LL k=((m-nowsp)/sp);
                res+=k*2;
                nowsp+=k*2*e[i].val;
                LL x=q.top();
                if(nowsp-x+sp<=m){
                    q.pop();
                    nowsp-=x;
                    nowsp+=sp;
                    res++;
                }
            }
        }
        return res;
    }
    void main(){
        memset(cho1,0,sizeof cho1);
        for(int i=1;i<=n;++i){
            e[++cnt]={x[i],1,i},e[++cnt]={(x[i]+y[i])/(double)2,2,i};
        }
        sort(e+1,e+1+cnt);
        LL ans=cal();
        cout<<ans<<endl;
    }

}
namespace BL{
    LL ans=0;
    int cho[N];
    void cal(){
        int res=0;
        for(int i=1;i<=n;++i){
            res+=cho[i];
        }
        if(ans<=res){
            ans=res;
        }
    }
    void dfs(int now,LL sp){
        if(now>n){
            cal();
            return;
        }
        for(int k=0;;++k){
            if(sp+k*(x[now]+y[now])<=m){
                cho[now]=k*2;
                dfs(now+1,sp+k*(x[now]+y[now]));
                if(sp+k*(x[now]+y[now])+x[now]<=m){
                    cho[now]=k*2+1;
                    dfs(now+1,sp+k*(x[now]+y[now])+x[now]);
                }

            }
            else
                break;
        }
    }
    void main(){
        dfs(1,0);
        cout<<ans<<endl;
    }
}
int main(){
    //6budui
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    TX::main();
    return 0;
}
