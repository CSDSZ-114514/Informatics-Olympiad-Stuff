#include<bits/stdc++.h>
using namespace std;
long long T,n,m;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        if(m>=23){cout<<"Yes"<<endl;continue;}
        bool A=true;
        for(int i=1;i<=m;i++){
            if(n%i!=i-1){
                cout<<"Yes"<<endl;
                A=false;
                break;
            }
        }
        if(A){
            cout<<"No"<<endl;
        }
    }
    return 0;
}