#include<bits/stdc++.h>
using namespace std;
double a[1005][1005],eqs=1e-6;
long long n;
int gauss(){
    bool p=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(fabs(a[j][j])>eqs&&j<i)continue;
            if(fabs(a[j][i])>eqs){
                swap(a[i],a[j]);break;
            }
        }
        if(fabs(a[i][i])<eqs){
            p=true;
            continue;
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
        if(fabs(a[i][i])>eqs)a[i][n+1]/=a[i][i];
    }
    bool f2=true;
    if(p){
        for(int i=1;i<=n;i++){
            if(fabs(a[i][i])<eqs&&fabs(a[i][n+1])>eqs){
                return -1;
            }
            if(fabs(a[i][i])<eqs&&fabs(a[i][n+1])<eqs){
                f2=false;
            }
        }
        if(f2==false){
            return 0;
        }
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
    long long t=gauss();
    if(t==1){
        for(int i=1;i<=n;i++){
            cout<<fixed<<setprecision(2)<<"x"<<i<<"="<<a[i][n+1]<<endl;
        }
    }else if(t==-1){
        cout<<"-1";
    }else if(t==0){
        cout<<"0";
    }

    return 0;
}