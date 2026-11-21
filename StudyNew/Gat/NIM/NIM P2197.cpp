#include<bits/stdc++.h>
using namespace std;
long long T,n,k;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        long long p=0;
        for(int i=1;i<=n;i++){
            cin>>k;
            p=p^k;
        }
        if(p){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}