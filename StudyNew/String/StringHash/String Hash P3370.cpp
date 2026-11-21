#include<bits/stdc++.h>
using namespace std;
long long n;
const long long N=1e5+5;
const unsigned long long hs1=131,hs2=13331;
unsigned long long p[N];
unsigned long long buc[N],h[N];
unsigned long long inith(string s){
    for(int i=1;i<=s.size();i++){
        h[i]=h[i-1]*hs1+s[i-1];
    }
    return h[s.size()];
}
void initp(){
    p[0]=1;
    for(int i=1;i<=1500;i++){
        p[i]=p[i-1]*hs1;
    }
}
unsigned long long geth(long long l,long long r){
    return h[r]-h[l-1]*p[l-r+1];
}
int main(){
    initp();
    cin>>n;
    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        buc[i]=inith(str);
    }
    sort(buc+1,buc+n+1);
    cout<<unique(buc+1,buc+n+1)-buc-1;



}