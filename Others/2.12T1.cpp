#include<bit/stdc++.h>
using namespace std;
int main(){
    long long n,m,k;cin>>n>>m>>k;
    cout<<m*n-min(k,n);
    return 0;
}