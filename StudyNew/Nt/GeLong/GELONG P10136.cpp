#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],mina=1e10;
set<int> s;
set<int> s1;    
bool check(long long p){
    s1.clear();
    if(p>mina/4)return false;
    for(int i=1;i<=n;i++){
        s1.insert(a[i]%p);
        if(s1.size()>3)return false;
    }
    return true;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];mina=min(mina,a[i]);
    }
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-a-1;
    if(n<=3){
        long long ans=0;
        for(int i=1;i<=mina/4;i++)ans+=i;
        cout<<ans;
        return 0;
    }else{
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                long long v=abs(a[i]-a[j]);
                for(int k=1;k<=sqrt(v);k++){
                    if(v%k==0){
                        if(check(k)){
                            s.insert(k);
                        }
                        if(check(v/k)){
                            s.insert(v/k);
                        }
                    }
                }
            }
        }
    }
    long long ans=0;
    for(auto t:s){
        ans+=t;
    }
    cout<<ans;
    return 0;
}