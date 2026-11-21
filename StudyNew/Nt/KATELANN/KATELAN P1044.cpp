#include<bits/stdc++.h>
using namespace std;
long long n;
long long h[105];
int main(){
    cin>>n;
    h[1]=1;
    h[0]=1;
    for(int i=2;i<=n;i++){
        h[i]=h[i-1]*(4*i-2)/(i+1);
    }
    cout<<h[n];
}