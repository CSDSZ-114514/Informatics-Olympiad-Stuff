#include<bits/stdc++.h>
using namespace std;
string s2;
long long n;
string s1[100005];
long long tr[1000005][8],idx,cnt[10000005],ans;
map<char, long long> m;
void insect(string s){
    long long p=0;
    for (int i = 0; i < s.size();i++){
        long long j =m[s[i]];
        if(tr[p][j]){
            p = tr[p][j];
        }else{
            tr[p][j] = ++idx;
            p = tr[p][j];
        }
    }
    cnt[p]++;
}
bool vis[1505][250005];
void dfs(long long i,long long p){
    if(i==s2.size()){
        ans += cnt[p];
        cnt[p] = 0;
        return;
    }
    if(vis[i][p]){
        return;
    }
    vis[i][p] = 1;
    if(s2[i]=='*'){
        dfs(i + 1, p);
        for (int j = 1; j <= 4;j++){
            if(tr[p][j]){
                dfs(i, tr[p][j]);
            }
        }
    }else if(s2[i]=='?'){
        for (int j = 1; j <= 4;j++){
            if(tr[p][j]){
                dfs(i+1, tr[p][j]);
            }
        }
    }else{
        if(tr[p][m[s2[i]]]){
            dfs(i+1, tr[p][m[s2[i]]]);
        }
    }
}
int main(){
    cin >> s2;
    cin >> n;
    m['A'] = 1;
    m['C'] = 2;
    m['T'] = 3;
    m['G'] = 4;
    for (int i = 1; i <= n;i++){
        cin >> s1[i];
        insect(s1[i]);
    }
    dfs(0, 0);
    cout << n - ans;
    return 0;
}