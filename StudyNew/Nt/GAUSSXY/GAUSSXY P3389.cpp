#include<bits/stdc++.h>
using namespace std;
double a[1005][1005],eqs=1e-6;
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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            cin>>a[i][j];
        }
    }
    if(gauss()){
        for(int i=1;i<=n;i++){
            cout<<fixed<<setprecision(2)<<a[i][n+1]<<endl;
        }
    }else{
        cout<<"No Solution";
    }

    return 0;
}