#include<bits/stdc++.h>
using namespace std;
string s;
const long long MOD = 1000000007LL;
long long a[1000005];char op[1000005];
long long mul[1000005],mmul[1000005];
set<pair<long long, long long>> sep;
long long ksm(long long a,long long b) {
    long long res=1;
    while(b){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
long long get_prod(int l,int r) {
    return mul[r]*mmul[l-1]%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    string num="";
    long long cnt=0;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i]))num+=s[i];
        else{
            a[++cnt]=stoll(num)%MOD;
            op[cnt]=s[i];
            num.clear();
        }
    }
    a[++cnt]=stoll(num)%MOD;

    mul[0]=1;
    for(int i=1;i<=cnt;i++) {
        mul[i]=mul[i-1]*a[i]%MOD;
    }
    mmul[cnt]=ksm(mul[cnt],MOD-2);
    for(int i=cnt-1;i>=0;i--) {
        mmul[i]=mmul[i+1]*a[i+1]%MOD;
    }

    int cnt2=1;
    for(int i=1;i<cnt;i++) {
        if(op[i]!='*'){
            sep.insert({cnt2,i});
            cnt2=i+1;
        }
    }
    sep.insert({cnt2,cnt});

    long long ans=0;
    for (auto it=sep.begin();it!=sep.end();it++) {
        long long l=it->first,r=it->second;
        long long fh=(l==1)?1:(op[l-1]=='+'?1:-1);
        ans=(ans+fh*get_prod(l,r))%MOD;
    }
    ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<"\n";
    
    long long q;
    cin>>q;
    while (q--) {
        long long k;char c;
        cin>>k>>c;
        if (op[k]=='*'&&c!='*') {
            auto it=sep.upper_bound({k+1,0});it--;
            long long L=it->first,R=it->second;sep.erase(it);

            int fho=(L==1)?1:(op[L-1]=='+'?1:-1);
            ans=(ans-fho*get_prod(L,R))%MOD;
            
            op[k]=c;
            
            sep.insert({L,k});
            sep.insert({k+1,R});
            
            ans=(ans+fho*get_prod(L,k))%MOD;
            
            int fh2=(c=='+')?1:-1;
            ans=(ans+fh2*get_prod(k+1,R))%MOD;
            
            ans=(ans%MOD+MOD)%MOD;
            cout<<ans<<"\n";
        }
    }
}