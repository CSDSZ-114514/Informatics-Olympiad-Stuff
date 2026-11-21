#include "perm.h"
long long pre[1000005], bck[1000005];
bool vis[1000005];
void init(int c, int t) { return; }
std::vector<int> perm(int n) {
    std::vector<int> ans(n, 0);
    long long pos = n - 1;
    pre[0] = query(0, 0);
    vis[pre[0]] = true;
    for (int i = 1; i <= n; i++) {
        pre[i] = query(0, i);
        if(pre[i]!=pre[i-1]){
            vis[i] = true;
            ans[i] = pre[i];
        }
        if (!pre[i]) {
            pos = i;
            break;
        }
    }
    for (int i = n - 1; i >= pos; i--) {
        bck[i] = query(i, n - 1);
        if(bck[i]!=bck[i+1]){
            vis[i] = true;
            ans[i] = bck[i];
        }
        if(!bck[i]){
            break;
        }
    }
    vis[ans[0]] = true;
    vis[ans[0]] = false;

    return ans;
}
