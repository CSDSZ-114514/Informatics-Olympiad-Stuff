#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,m;
const int N=5e4+5,M=998244353;
int a[N];
namespace BL{
    int ans=0;
    struct Item{
        int val;
        double k;
        int id;
        int w;
        bool operator<(const Item& o)const{
            if(k!=o.k)
                return k>o.k;
            if(val!=o.val)
                return val>o.val;
            return id<o.id;
        }
    };
    int cho[N];
    int getbag(){
        int f[N<<1];
        memset(f,0,sizeof f);
        for(int i=1;i<=n;++i){
            for(int v=m;v>=0;--v){
                if(v-cho[i]>=0)
                    f[v]=max(f[v],f[v-cho[i]]+a[i]);
            }
             //cerr<<"i: "<<i<<":  "<<f[m]<<'\n';
        }
        return f[m];
    }
    int getr(){
        vector<Item>e;
        for(int i=1;i<=n;++i)
        e.push_back({a[i],(double)a[i]/(double)cho[i],i,cho[i]});
        sort(e.begin(),e.end());
        int resm=m;
        int maxval=0;
        for(int j=0;j<e.size();++j){
        	Item i=e[j];
            if(resm>=i.w){
                resm-=i.w;
                maxval+=i.val;
            }
        }
        return maxval;
    }
    void cal(){
        int t1=getbag(),t2=getr();
        //cerr<<"t1:"<<t1<<"t2:"<<t2<<'\n';
        if(t1==t2)  ++ans;
    }
    void dfs(int now){
        if(now>n){
            cal();
            return;
        }
        cho[now]=1;
        dfs(now+1);
        cho[now]=2;
        dfs(now+1);
        cho[now]=0;
    }
    void main(){
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
}
int phi(int a,int b){
    int res=1;
    while(b){
        if(b&1)
            res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
int fac[N];
void init(){
    fac[0]=1;
    for(int i=1;i<N;++i)
        fac[i]=(fac[i-1]*i)%M;
}

int c(int n,int m){
    if(m>n) return 0;
    int infm=phi(fac[m],M-2),infnm=phi(fac[n-m],M-2);
    return ((fac[n]*infm)%M*infnm)%M;
}
bool cmp(int a,int b){
        return a>b;
    }
namespace Tp{

    void main(){

        int ans=0;
        //1?????
        ans=(ans+phi(2,n-1))%M;
        int k=0;
        for(int i=2;i<=n;++i)
            if(a[1]<a[i]*2)
                ++k;
        //22222222  ??????
        ans=(ans+phi(2,n-1-k))%M;
        //211??????
        ans=(ans+(c(k,2)*phi(2,n-3))%M)%M;
        cout<<ans<<'\n';

    }
}
namespace T2{
    void main(){
        int ans=phi(2,n);
        cout<<ans<<'\n';
    }
}
signed main(){
    //di11zu  yingwei24
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int C,T;
    cin>>C>>T;
    init();
    while(T--){
            sort(a+1,a+1+n,cmp);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        if(C<=3){
            BL::main();
        }
        else if(C==18)
            T2::main();
        else
            Tp::main();
    }


    return 0;
}
