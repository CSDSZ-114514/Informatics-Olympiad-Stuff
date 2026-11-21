#include<bits/stdc++.h>
using namespace std;
long long n,a[105],b[105][10005],c[105][10005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=a[i];j++){
            cin>>b[i][j];
            cin>>c[i][j];
        }
        bool flag=true;
        for(int j=1;j<=a[i];j++){
            for(int k=j+1;k<=a[i];k++){
                if(abs(c[i][j]-c[i][k])%(__gcd(b[i][j],b[i][k]))!=0){
                    flag=false;
                }
            }
        }
        if(flag){
            cout<<"possible"<<endl;
        }else{
            cout<<"impossible"<<endl;
        }
    }
    return 0;
}