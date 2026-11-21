#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+5;

long long n;
long long a[N],b[N],ne[N];
int main(){
    cin>>n;
    long long asum=0,bsum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];asum+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];bsum+=b[i];
    }
    long long x=(bsum-asum)/n;
    if(n*x!=bsum-asum){cout<<-1;return 0;}
    ne[1]=0;
    for(int i=1;i<=n;i++){
        a[i]+=x;
    }
    for(int i=2,j=0;i<=n;i++){
        while(j&&b[i]!=b[j+1]){
            j=ne[j];
        }
        if(b[i]==b[j+1]){
            j++;
        }
        ne[i]=j;
    }
    for(int i=1;i<=n;i++){
        a[i+n]=a[i];
    }
    for(int i=1,j=0;i<=2*n;i++){
        while(j&&a[i]!=b[j+1]){
            j=ne[j];
        }
        if(a[i]==b[j+1]){
            j++;
        }
        if(j==n){
            cout<<i-n;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}