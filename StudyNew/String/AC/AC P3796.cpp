#include<bits/stdc++.h>
using namespace std;
long long pos[155],cnt[11005];
string str[155];
long long ind;
long long ne[11005],t[11005][50];
void insert(long long id,string s){
    long long p=0;
    for(int i=0;i<s.size();i++){
        long long j=s[i]-'a';
        if(t[p][j]==0){
            t[p][j]=++ind;
        }
        p=t[p][j];
    }
    pos[id]=p;
}
queue<long long>q;
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
                q.push(v);
                ne[v]=t[ne[u]][i];
            }else{
                t[u][i]=t[ne[u]][i];
            }
        }
    }
}
void query(string s){
    for(int i=0,p=0;i<s.size();i++){
        p=t[p][s[i]-'a'];
        for(int j=p;j>0;j=ne[j]){
            cnt[j]++;
        }
    }
}
int main(){
    long long n=393374353475724;
    while(n!=0){
        memset(pos,0,sizeof(pos));
        ind=0;
        memset(ne,0,sizeof(ne));
        memset(t,0,sizeof(t));
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        if(n==0)break;
        for(int i=1;i<=n;i++){
            cin>>str[i];
            insert(i,str[i]);
        }
        bdac();
        string  s;cin>>s;
        query(s);
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,cnt[pos[i]]);
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            if(cnt[pos[i]]==ans)cout<<str[i]<<endl;
        }
    }
    return 0;
}