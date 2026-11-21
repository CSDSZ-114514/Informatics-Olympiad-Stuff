#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct ED {
    long long u, v, w;
};
ED e[1000005];
long long fa[1000005];
bool cmp(ED x, ED y) { return x.w < y.w; }
long long find(long long x) {
	if(x == fa[x]) {
		return x;
	} else {
		return fa[x] = find(fa[x]);
	}
}
void heb(long long x, long long y) {
	fa[find(x)] = find(y);
} 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <=m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    sort(e + 1, e + 1 + m, cmp);
    long long sum = 0,cnt=0;
    for (int i = 1; i <= m;i++){
        if(find(e[i].u)==find(e[i].v)){
            continue;
        }else{
            heb(e[i].u, e[i].v);
            sum += e[i].w;
            cnt++;
        }
    }
    if(cnt<n-1){
        cout << "orz";
    }else{
        cout << sum;
    }
    return 0;
}