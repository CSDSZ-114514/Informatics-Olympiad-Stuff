#include<bits/stdc++.h>
using namespace std;
char a[1005][1005],b[1005][1005];long long cntb;
int main(){
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
            if(b[i][j]!=a[i][j])cntb++;
        }
    }
    if(cntb<=m*n/2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='X')a[i][j]='.';
                else a[i][j]='X';
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}