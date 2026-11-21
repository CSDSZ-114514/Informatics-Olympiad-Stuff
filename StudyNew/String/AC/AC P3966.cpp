#include<bits/stdc++.h>
using namespace std;
long long pos[1550000],cnt[1100005];
string str[1550000];
long long ind;
long long ne[1100005],t[1100005][50];
void insert(long long id,string s){
    long long p=0;
    for(int i=0;i<s.size();i++){
        long long j=s[i]-'a';
        if(t[p][j]==0){
            t[p][j]=++ind;
        }
        p=t[p][j];
        cnt[p]++;
    }
    pos[id]=p;

}
queue<long long> q;
stack<long long> st;
void bdac(){
    for(int i=0;i<=25;i++){
        if(t[0][i])q.push(t[0][i]);
    }
    while(!q.empty()){
        long long u=q.front();
        st.push(u);
        q.pop();
        for(int i=0;i<=25;i++){
            long long v=t[u][i];
            if(v){
                q.push(v);
                ne[v]=t[ne[u]][i];
                //cnt[v]++;
            }else{
                t[u][i]=t[ne[u]][i];
            }
        }
    }
    while(!st.empty()){
        long long u=st.top();
        st.pop();
        cnt[ne[u]]+=cnt[u];
    }
}
int main(){
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i];
        insert(i,str[i]);
    }
    bdac();
    for(int i=1;i<=n;i++){
        cout<<cnt[pos[i]]<<endl;
    }
    return 0;
}