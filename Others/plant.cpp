#include<bits/stdc++.h>
using namespace std;
long long t,id;
const long long P=998244353;
bool g[10005][10005];long long f[10005][10005],ansc,ansf;
long long n,m,ccc,fff;
int main(){
    cin>>t>>id;
    while(t--){
        cin>>n>>m>>ccc>>fff;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char a;cin>>a;
                if(a=='1')g[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=m-1;j>=1;j--){
                if(!g[i][j]&&!g[i][j+1]){
                    f[i][j]=(f[i][j+1]+1)%P;
                }
            }
        }
        for(int j=1;j<=m;j++){
            long long ch=0,cc=0;
            for(int i=1;i<=n;i++){
                if(g[i][j]){
                    ch=0;cc=0;continue;
                }
                int sum=f[i][j]*ch%P;
                ansc=(sum+ansc)%P;
                ch=(ch+f[i-1][j])%P;
                ansf=(ansf+cc)%P;
                cc=(cc+sum)%P;
            }
        }
        cout<<ansc*ccc%P<<" "<<ansf*fff%P<<endl;
        memset(g,0,sizeof(g));
        memset(f,0,sizeof(f));
        ansc=0;ansf=0;n=0;m=0;ccc=0;fff=0;
    }
}