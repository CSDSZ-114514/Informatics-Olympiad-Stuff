#include<bits/stdc++.h>
using namespace std;
long long k,a[1000005];
int main(){
    cin>>k;
    long long s=0;
    for(int i=1;i<=k;i++){cin>>a[i];s=(s^a[i]);}
    //cout<<s;
    if(s==0){cout<<"lose";return 0;}
    for(int i=1;i<=k;i++){
        if(a[i]>(a[i]^s)){
            cout<<(a[i]-(a[i]^s))<<" "<<i<<endl;
            for(int j=1;j<=k;j++){
                if(j!=i)cout<<a[j]<<" ";
                else cout<<(a[j]^s)<<" ";
            }
            return 0;
        }
    }
    
    return 0;
}