#include<bits/stdc++.h>
#define int long long
#define for_(i,a,b) for(int i=a;i<=b;i++)
#define _for(i,a,b) for(int i=a;i>=b;i--)
#define ull unsigned long long
using namespace std;

namespace IO{
	#define filein(data) freopen(data".in","r",stdin)
	#define fileout(data) freopen(data".out","w",stdout)
	#define File(data) filein(data),fileout(data)
	inline void read(int &x){
		x=0;int f=1;char ch=getchar();
		while('0'>ch||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
		while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
		x=x*f;
	}
}
using namespace IO;
const int N = 1e6+5;
const int mod = 998244353;

int n,m;
int a[N],ans=0;

inline int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		x=x*x%mod; y>>=1;
	}
	return ans;
}

pair<int,int> B[N],A[N];
bool vis[N];
inline void dfs(int step){
    if(step==n+1){   
        for_(i,1,n) A[i]=B[i];
        sort(A+1,A+1+n,[](pair<int,int>a,pair<int,int>b){return (a.first!=b.first)?(a.first<b.first):(a.second>=b.second);});int w=m,s=0;
        for_(i,1,n){
            if(w>=A[i].second){
                s-=A[i].first;w-=A[i].second;
                vis[i]=1;
            }
        }
        int pos1=0,pos2=0,posVis=0;
        for_(i,1,n){
            if(vis[i] && A[i].second==1) {pos1=posVis;posVis=i;}
            if(!vis[i]){
                if(A[i].second==2&&!pos2)
                    pos2=i;
            }
        }
        if(w) {if(A[pos2].first<A[posVis].first/2 && posVis!=0) ans++;}
        else if(A[pos2].first<(A[posVis].first+A[pos1].first)/2 && pos1!=0 && posVis!=pos1) {ans++;}
        for_(i,1,n) vis[i]=0;
        return;
    }
    B[step] = make_pair(-2*a[step],1);
    dfs(step+1);
    B[step] = make_pair(-a[step],2);  
    dfs(step+1);
    B[step] = make_pair(0,0);
}
signed main(){
    File("sale");//T2 baoli
    int c,t;read(c),read(t);
    while(t--){
        ans=0;read(n),read(m);
        for_(i,1,n) read(a[i]);
        sort(a+1,a+1+n,[](int x,int y){return x>y;});
        if(c<=5){
            dfs(1);
            cout << qpow(2,n)-ans << endl;
        }
        else{
            dfs(1);
            cout << qpow(2,n)-ans << endl;
        }
    }
} 
