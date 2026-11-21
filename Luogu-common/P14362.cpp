#include<bits/stdc++.h>
using namespace std;
long long fa[100005],co[15];
long long ans=1e9;
bool used[15];
long long n,m,k,cnt;
struct ED{
    long long u,v,w;
}e[100005];
long long find(long long x) {
	if(x == fa[x]) {
		return x;
	} else {
		return fa[x] = find(fa[x]);
	}
}
long long kruskal() {
	for(int i=1; i<=n; i++) {
		fa[i] = i;
	}
	long long sum = 0;
	for(int i=1; i<=cnt; i++) { 
		long long x = find(e[i].u); 
		long long y = find(e[i].v);
        //cout<< e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
        if(e[i].u>n||e[i].v>n){
            if(!used[max(e[i].u,e[i].v)-n])continue;
        }
		if(x != y) {
            //cout<< e[i].u<<" "<<e[i].v<<endl;
			sum += e[i].w; 
			fa[x] = y; 
		}
	}
    //cout<<endl<<endl<<endl;
	return sum;
}
bool cmp(ED x,ED y){
    return x.w<y.w;
} 
void dg(long long x,long long cost){
    if(x==k+1){
        // for(int i=1;i<=k;i++){
        //     cout<<used[i]<<" ";
        // }
        //cout<<cost<<endl;
        //cout<<kruskal()+cost<<endl;
        ans=min(ans,kruskal()+cost);
        return;
    }else{
        used[x+1]=0;
        dg(x+1,cost);
        used[x+1]=1;
        dg(x+1,cost+co[x+1]);
        used[x+1]=0;
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        e[++cnt].u=a;e[cnt].v=b;e[cnt].w=c;
    }
    for(int i=1;i<=k;i++){
        long long a,c;
        cin>>c;co[i]=c;
        for(int j=1;j<=n;j++){
            cin>>a;
            e[++cnt].u=j;
            e[cnt].v=i+n;
            e[cnt].w=a;
        }
    }
    sort(e+1, e+cnt+1, cmp);
    dg(0,0);
    cout<<ans;
    return 0;
}