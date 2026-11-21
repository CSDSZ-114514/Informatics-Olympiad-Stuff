#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b;
bool mp[50][50];
long long f[50][50];
long long dx[10]={2,2,-2,-2,1,1,-1,-1};
long long dy[10]={1,-1,1,-1,2,-2,2,-2}; 
int main(){
    cin>>n>>m>>a>>b;
    for(int i=0;i<=7;i++){
        long long tx=max(a+dx[i],(long long)0);
        long long ty=max(b+dy[i],(long long)0);
        mp[tx][ty]=1;
    }
    f[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(!mp[i][j]){
                f[i][j]=f[max(i-1,0)][j]+f[i][max(j-1,0)];
            }
        }
    }
    cout<<f[n][m];
    return 0;
}