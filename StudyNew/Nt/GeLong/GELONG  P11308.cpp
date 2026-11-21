#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m,k,p;
        cin>>n>>m>>k>>p;
        if(k<=m-p/n)cout<<"Together"<<endl;
        else if(k>m)cout<<"Divide"<<endl;
        else cout<<"Chance"<<endl;
    }       
    return 0;
}