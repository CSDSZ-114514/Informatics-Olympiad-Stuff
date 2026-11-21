#include<bits/stdc++.h>
using namespace std;
namespace Main{
const int N=5e3+10,mod=998244353;
using lnt=long long;using Pair=pair<lnt,int>;
int c,T,n,m;lnt seq[N];
lnt fpow(lnt x,lnt k){
    lnt res=1;
    while(k){
        if(k&1)res*=x,res%=mod;
        x*=x;x%=mod;k>>=1;
    }return res;
}
namespace Brute{
Pair tmp[N];
int main(){
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                tmp[j]={seq[j],2};
            }else{
                tmp[j]={seq[j]*2,1};
            }
            //cerr<<' '<<tmp[j].first<<' ';
        }
        sort(tmp,tmp+n,[](const Pair &a,const Pair &b){return a.first>b.first || (a.first==b.first && a.second>b.second);});
        lnt pre=0,suf=0,swp=0,rem=m;bool missed=0,mempre=0;
        for(int j=0;j<n;j++){
            if(rem<=0)break;
            if(!missed && tmp[j].second==1){mempre=1;pre=(tmp[j].first>>1);rem--;continue;}
            if(missed && tmp[j].second==1){suf=(tmp[j].first>>1);rem--;continue;}
            if(rem<tmp[j].second){
                if(missed)continue;
                missed=true;
                swp=tmp[j].first;
            }else rem-=2;
        }
        if(!mempre || !missed || (missed&&pre+suf>=swp)){
            ans++;ans%=mod;
        }
        //else cerr<<i<<'\n';
    }
    return ans;
}
lnt ONEBUY(){
    lnt ans=0;
    sort(seq,seq+n,[](int a,int b){return a>b;});
    for(int i=1;i<=n;i++){
        if(2*seq[i]<=seq[0])break;
        if(seq[i]==seq[0])continue;
        int L=i+1,R=n-1,id=n;
        while(L<=R){
            int mid=(L+R)>>1;
            if(seq[mid]<seq[0]-seq[i]){R=mid-1;id=mid;}
            else{L=mid+1;}
        }
        //cerr<<id<<' '<<n-id<<' ';
        ans+=fpow(2,n-id);
        ans%=mod;
    }
    ans=(fpow(2,n)-ans)%mod;ans+=mod;ans%=mod;
    return ans;
}
}
void main(){
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%lld",&seq[i]);
        }lnt ans=0;
        if(c<=5)ans=Brute::main();
        if(m==2)ans=Brute::ONEBUY();
        if(c==16 || c==18)ans=fpow(2,n);
        if(c==17){
            ans=fpow(2,n);
            sort(seq,seq+n);
            if(seq[0]*2>seq[1] && seq[1]>seq[0])ans--;
            ans+=mod;ans%=mod;
        }
        if((c>=10 && c<=12) ||(c==19)||c==20){

        }
        printf("%lld\n",ans);
    }
}
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    Main::main();
    return 0;
}
