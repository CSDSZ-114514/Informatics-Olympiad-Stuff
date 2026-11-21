#include<bits/stdc++.h>
using namespace std;
long long T;
long long t[3000005][70],ind,cnt[3000005];
long long ys(char c){
    if(c>='A'&&c<='Z'){
        return (long long)(c-'A')+1;
    }else  if(c>='a'&&c<='z'){
        return (long long)(c-'a')+27;
    }else  if(c>='0'&&c<='9'){
        return (long long)(c-'0')+53;
    }
}
bool insect(string s){
    long long p=0;
    for(int i=0;i<s.size();i++){
        long long j=ys(s[i]);
        if(t[p][j]==0){
            t[p][j]=++ind;
        }
        p=t[p][j];
        cnt[p]++;
    }
    
    return 0;
}
long long qwerty(string s){
    long long p=0;
    for(int i=0;i<s.size();i++){
        long long j=ys(s[i]);
        if(t[p][j]){
            p=t[p][j];
        }else{
            return 0;
        }
    }
    return cnt[p];
}
int main(){
    cin>>T;
    while(T--){
        long long n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            string s;cin>>s;
            insect(s);
        }
        for(int i=1;i<=q;i++){
            string s;cin>>s;
            cout<<qwerty(s)<<endl;
        }
        for(int i=0;i<=ind;i++){
            for(int j=0;j<=62;j++){
                t[i][j]=0;
            }
            cnt[i]=0;
        }
        ind=0;
    }
    return 0;

}