#include<bits/stdc++.h>
using namespace std;
long long n;
long long t[1000005][50],cnt[1000005],ne[1000050];
long long ind;
void insect(string s){
    long long p=0;
    for(int i=0;i<s.size();i++){
        long long j=s[i]-'a';
        if(t[p][j]==0){
            t[p][j]=++ind;
        }
        p=t[p][j];
        
    }
    cnt[p]++;
}
queue<long long> q;
void bdac(){
    for(int i=0;i<=25;i++){
        if(t[0][i])q.push(t[0][i]);
    }
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        for(int i=0;i<=25;i++){
            long long v=t[u][i];
            if(v){
                ne[v]=t[ne[u]][i];
                q.push(v);
            }else{
                t[u][i]=t[ne[u]][i];
            }
        }
    }
}
long long query(string s){
    long long ans=0;
    for(int i=0,p=0;i<s.size();i++){
        p=t[p][s[i]-'a'];
        for(int j=p;j&&cnt[j]!=-1;j=ne[j]){
            ans+=cnt[j];
            cnt[j]=-1;
        }
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        insect(s);
    }
    bdac();
    string s;cin>>s;
    cout<<query(s);

    return 0;
}