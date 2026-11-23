#include <bits/stdc++.h>
using namespace std;
// struct NODE{
// 	long long tp,p,v,mul,sum;
// }a[1000005];
// vector<long long> e[1000005];
// long long n,m,q,f[1000005],b[1000005],d[1000005],ord[1000005],cnt,mod=998244353;
// void topo(){
// 	queue<long long>q;
// 	for(int i=1;i<=n;i++){
// 		if(d[i]==0)q.push(i);
// 	}
// 	while(!q.empty()){
// 		long long u=q.front();
// 		q.pop();
// 		ord[++cnt]=u;
// 		for(auto t:e[u]){
// 			d[t]--;
// 			if(d[t]==0){
// 				q.push(t);
// 			}
// 		}
// 	}
// }
// void getmul(){
// 	for(int i=m;i>=1;i--){
// 		long long u=ord[i];
// 		for(auto v:e[u]){
// 			a[u].mul=(a[u].mul*a[v].mul)%mod;
// 		}
// 	}
// }
// void getsum(){
// 	for(int i=1;i<=m;i++){
// 		long long u=ord[i],now=1;
// 		for(int j=e[u].size()-1;j>=0;j--){
// 			long long v=e[u][j];
// 			a[v].sum=(a[v].sum+a[u].sum*now%mod)%mod;
// 		}
// 	}
// }
// int main(){
// 	cin>>n;
// 	for(int i=1;i<=n;i++)cin>>b[i];
// 	cin>>m;
// 	for(int i=1;i<=m;i++){
// 		cin>>a[i].tp;
// 		if(a[i].tp==1){
// 			cin>>a[i].p>>a[i].v;
// 			a[i].mul=1;
// 		}else if(a[i].tp==2){
// 			cin>>a[i].v;
// 			a[i].mul=a[i].v;
// 		}else {
// 			a[i].mul=1;
// 			long long len=0;
// 			cin>>len;
// 			for(int j=1;j<=len;j++){
// 				long long v;
// 				cin>>v;
// 				e[i].push_back(v);
// 				d[v]++;
// 			}
// 		}
// 	}
// 	topo();
// 	getmul();
// 	cin>>q;
// 	for(int i=1;i<=q;i++){
// 		cin>>f[i];
// 	}
// 	long long now=1;
// 	for(int i=q;i>=1;i--){
// 		a[f[i]].sum=(a[f[i]].sum+now)%mod;
// 		now=now*a[f[i]].mul%mod;
// 	}
// 	getsum();
// 	for(int i=1;i<=n;i++){
// 		b[i]=b[i]*now%mod;
// 	}
// 	for(int i=1;i<=m;i++){
// 		if(a[i].tp==1){
// 			b[a[i].p]=(b[a[i].p]+a[i].sum*a[i].v)%mod;
// 		}
// 	}
// 	for(int i=1;i<=n;i++){
// 		cout<<b[i]<<" ";
// 	}
// 	return 0;
// }
const long long mod = 998244353;
struct FUNC {
    long long tp, p, v, mul, cnt;
} f[1000005];
vector<long long> e[1000005];
long long n, m, a[1000005];
long long rd[1000005], ord[1000005];
void topo() {
    queue<long long> q;
    for (int i = 1; i <= n; i++) {
        if (rd[i] == 0) {
            q.push(i);
        }
    }
    long long cnt = 0;
    while (!q.empty()) {
        long long u = q.front();
        q.pop();
        ord[++cnt] = u;
        for (auto v : e[u]) {
            rd[v]--;
            if (rd[v] == 0) {
                q.push(v);
            }
        }
    }
}
void getmul() {
    for (int i = m; i >= 1; i--) {
        long long u = ord[i];
        for (auto v : e[u]) {
            f[u].mul = (f[u].mul * f[v].mul) % mod;
        }
    }
    return;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        long long t;
        cin >> t;
        f[i].tp = t;
        if (t == 1) {
            cin >> f[i].p >> f[i].v;
            f[i].mul = 1;
        } else if (t == 2) {
            cin >> f[i].v;
            f[i].mul = f[i].v;
        } else {
            long long c;
            cin >> c;
            for (int j = 1; j <= c; j++) {
                long long v;
                cin >> v;
                e[i].push_back(v);
                rd[v]--;
            }
        }
    }
    topo();
    getmul();
    long long q;
    cin >> q;
    for (int i = 1; i <= q;i++){
        
    }
}
