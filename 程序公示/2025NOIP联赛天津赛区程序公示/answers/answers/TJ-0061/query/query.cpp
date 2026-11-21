#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int N=50010;
const long long=pow(2,64);
int a[N],s[N];
int n;
int q;
        int k[N];

int main(){
    
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        s[i]=s[i-1]+a[i];
        }
    cin>>q;
    while(q--){
        int L,R;
        int t=0;
        cin>>L>>R;
        for(int x=L;x<=R;x++)
        for(int i=1;i<=n;i++){
            for(int j=max(1,i-x+1);j<=n-x+1;j++)
            k[t++]+=s[j+x]-s[j+x-1];
        }
    }
    return 0;
}//should AC.( ._.)