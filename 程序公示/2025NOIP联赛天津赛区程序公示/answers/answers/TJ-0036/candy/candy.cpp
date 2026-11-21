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

int f[N],ans,tot;
int a[N],b[N],sum[N];
signed main(){
    File("candy");
    int n,m;read(n);read(m);
    for_(i,1,n){
        read(a[i]);read(b[i]);
        sum[i] = (a[i]+b[i]);
    }
    sort(sum+1,sum+1+n);sort(a+1,a+1+n);
    for_(i,1,n){
        if(a[i]>sum[1]) break;
        ans+=a[i],tot++;
    }
    int answers=m/sum[1]*2,w=m%sum[1],tot=0;
    int Ansmax = answers+(w>=a[1]?1:0);
    for_(i,1,n){
        if(w>=a[i]) {answers++,w-=a[i];}
        else {
            if(a[i]*2<sum[1]) {answers--,w+=sum[1]-a[i],tot=i;}
        }
    }
    if(tot){
        if(w+a[tot]>sum[1]) answers++;
    }
    cout << max(Ansmax,answers);
} 
