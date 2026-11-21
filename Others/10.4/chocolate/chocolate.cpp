#include<bits/stdc++.h>
using namespace std;
long long n,m,xi[100005],yi[100005],sum;
int main(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>xi[i];sum+=xi[i];
    }
    for(int i=1;i<m;i++){
        cin>>yi[i];sum+=yi[i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            sum+=min(xi[i],yi[j]);
        }
    }
    cout<<sum;
}