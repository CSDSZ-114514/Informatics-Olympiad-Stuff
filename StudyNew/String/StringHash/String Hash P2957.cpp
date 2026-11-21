#include<bits/stdc++.h>
using namespace std;
long long n;
const long long N=1e5+5;
const unsigned long long hs1=131,hs2=13331;
unsigned long long p[N];
unsigned long long buc[N],h[N],h1[N];
unsigned long long inith(string s){
    for(int i=1;i<=s.size();i++){
        h[i]=h[i-1]*hs1+s[i-1];
    }
    return h[s.size()];
}
unsigned long long inith2(string s){
    for(int i=1;i<=s.size();i++){
        h1[i]=h1[i-1]*hs1+s[i-1];
    }
    return h1[s.size()];
}
void initp(){
    p[0]=1;
    for(int i=1;i<=1500;i++){
        p[i]=p[i-1]*hs1;
    }
}
unsigned long long geth(long long l,long long r){
    return h[r]-h[l-1]*p[r-l+1];
}
unsigned long long geth1(long long l,long long r){
    return h1[r]-h1[l-1]*p[r-l+1];
}
int main(){
    initp();
    string str;
    cin>>str;
    string str1;
    cin>>str1;
    inith(str);
    inith2(str1);
    long long maxcnt=-1e9;
    for(int l1=1;l1<=str.size();l1++){
        for(int l2=1;l2<=str.size();l2++){
            for(int r1=1;r1<=str1.size();r1++){
                for(int r2=1;r2<=str1.size();r2++){
                    if(geth(l1,r1)==geth1(l2,r2)&&r2-l2==r1-l1){
                        maxcnt=max(maxcnt,(long long)r1-l1+1);
                    }
                }
            }
        }
    }
    cout<<maxcnt;


}