#include<bits/stdc++.h>
using namespace std;
string s2;
long long n;
string s1[1000005];
long long tr[1000005][30], cnt[1000005], idx;
void insect(string s){
    long long p=0;
    for (int i = 0; i < s.size();i++){
        long long j = s[i] - 'a';
        if(tr[p][j]){
            p = tr[p][j];
        }else{
            tr[p][j] = ++idx;
            p=tr[p][j];
        }
    }
    cnt[p]=s.size();
}
long long ne[100005];
void build(){
    queue<long long> q;
    for (int i = 0; i <= 25;i++){
        if(tr[0][i])
            q.push(tr[0][i]);
    }
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        for (int i = 0; i <= 25;i++){
            long long v = tr[u][i];
            if(!v){
                tr[u][i] = tr[ne[u]][i];
            }
            else{
                ne[v] = tr[ne[u]][i];
                q.push(v);
            }
        }
    }
}
long long hisp[1000005];
deque<long long> q;
void query(string s){
    long long ans=0,p=0;
    for (int i = 0; i < s.size();i++){
        q.push_back(i);
        p = tr[p][s[i] - 'a'];
        hisp[i] = p;
        //cout << cnt[p];
        if(cnt[p]){//cout << 1111;
            for (int z = 1; z <= cnt[p];z++){
                q.pop_back();
            }
            p = hisp[q.back()];
        }
    }
}
int main(){
    cin >> s2;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> s1[i];
        insect(s1[i]);
    }
    build();
    query(s2);
    while(!q.empty()){
        cout << s2[q.front()];
        q.pop_front();
    }
    return 0;
}