#include<bits/stdc++.h>
using namespace std;
double a[1005][1005],eqs=1e-6,b[1005][1005];
long long n;
bool gauss(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(fabs(a[j][i])>eqs){
                swap(a[i],a[j]);break;
            }
        }
        if(fabs(a[i][i])<eqs){
            return 0;
        }
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            double t=a[j][i]/a[i][i];
            for(int k=i;k<=n+1;k++){
                a[j][k]-=a[i][k]*t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        a[i][n+1]/=a[i][i];
    }
    return 1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=2*(b[i+1][j]-b[i][j]);
            a[i][n+1]+=(b[i+1][j]*b[i+1][j]-b[i][j]*b[i][j]);
        }
    }
    gauss();

    for(int i=1;i<=n;i++){
        cout<<fixed<<setprecision(3)<<a[i][n+1]<<" ";
    }

    return 0;
}