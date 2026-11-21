#include<bits/stdc++.h>
using namespace std;
long long ne[1000005];
string  s1,s2;
int main(){
    cin>>s1>>s2;
    long long n=s1.size();
    long long m=s2.size();
    s1=" "+s1;
    s2=" "+s2;
    ne[1]=0;
    for(int i=2,j=0;i<=m;i++){
        while(j&&s2[i]!=s2[j+1]){
            j=ne[j];
        }
        if(s2[i]==s2[j+1]){
            j++;
        }
        ne[i]=j;
    }
    for(int i=1,j=0;i<=n;i++){
        while(j&&s1[i]!=s2[j+1]){
            j=ne[j];
        }
        if(s1[i]==s2[j+1]){
            j++;
        }
        if(j==m){
            cout<<i-m+1<<endl;
        }
    }
    for(int i=1;i<=(m);i++){
        cout<<ne[i]<<" ";
    }
    return 0;
}