#include<iostream>
#include<cstdlib>
#include<string.h>
#include<vector>
using namespace std;
const int MAXN = 8000;
const int MAXM = 800;
int t,m,n,ans = 0;
int father[MAXN];

int w[MAXN];//node value

bool isLeaf[MAXN];
bool set_n[MAXN][MAXN];
void push_up(int s,int w){
    set_n[s][w] = 1;
    if(father[s]){
        push_up(father[s],w);
    }
}
int value(){
    int v = 0;
    memset(set_n,0,sizeof(set_n));
    for(int i=1;i<=n;i++){
        push_up(i,w[i]);
    }
    for(int i=1;i<=n;i++){
        int j = 0;
        while(set_n[i][j]) j++;
        v += j;
    }
    return v;
}

void dfs(int s){
    for(int i=0;i<n;i++){
        if(!i&&!isLeaf[s]) continue;
        w[s] = i;
        if(s==n)
        ans = max(ans,value());
        else
        dfs(s+1);
    }
}

vector<int> son[MAXN];
vector<int> leaves;
int weights[MAXN];//child tree's value
//1.sure leaves
//2.get value by faster function
void init_leaves(){
    for(int i=1;i<=n;i++)
    if(isLeaf[i])
    leaves.push_back(i);
}

int value_(int s){//remember to init weights before use this
    if(weights[s]!=-1) return weights[s];
    if(!son[s].empty()){
        int cnt = 0;
        for(auto so:son[s]){
            cnt += value_(so);
        }
        weights[s] = cnt;
        int j = 0;
        while(set_n[s][j]){
            set_n[father[s]][j] = 1;
            j++;
        }
        w[s] = j;
        set_n[father[s]][j] = 1;
        weights[s] += j+1;
        return weights[s];
    }
    set_n[s][w[s]] = 1;
    set_n[father[s]][w[s]] = 1;
    int j = 0;
    while(set_n[s][j]) j++;
    weights[s] = j;
    return weights[s];
}

void guess_leaves(int idx){//O(n!*?)
    for(int i=0;i<leaves.size();i++){
        //cout << idx << " guess " << i << endl;
        w[leaves[idx]] = i;
        if(idx+1<leaves.size()) guess_leaves(idx+1);
        else{
            //cout << "guess end" << endl;
            memset(set_n,0,sizeof(set_n));
            fill(weights,weights+MAXN,-1);
            ans = max(ans,value_(1));
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> t;
    while(t--){
        memset(isLeaf,1,sizeof(isLeaf));
        cin >> n >> m;
        for(int i=2;i<=n;i++){
            cin >> father[i];
            isLeaf[father[i]] = 0;
            son[father[i]].push_back(i);
        }
        if(n<=7){
            dfs(1);
            cout << ans << "\n";
            continue;
        }
        init_leaves();
        //cout << "finish init" << leaves.size() << endl;
        guess_leaves(0);//wrong and slow
        cout << ans << "\n";
    }

    return 0;
}
