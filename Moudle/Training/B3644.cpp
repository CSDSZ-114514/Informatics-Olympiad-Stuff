#include<bits/stdc++.h>
using namespace std;
long long n;
long long d[100005];
vector<long long> e[100005];
bool toposort() {
    queue<long long> q;
    for (int i = 1; i <= n;i++){
        if(d[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        cout << u << " ";
        for(auto t:e[u]){
            d[t]--;
            if(d[t]==0){
                q.push(t);
            }
        }
    }
    return true; 
}
int main() {
    cin >> n;
    for (int i = 1; i <= n;i++){
        while(true){
            long long b;
            cin >> b;
            if(b==0){
                break;
            }
            e[i].push_back(b);
            d[b]++;
        }
    }
    toposort();

    return 0; 
}