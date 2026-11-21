#include<bits/stdc++.h>
using namespace std;
long long l;
string s2;
long long ne[1000006];
int main(){
    cin>>l>>s2;
    s2=" "+s2;
    long long m=s2.size()-1;
    for(int i=2,j=0;i<=m;i++){
        while(j&&s2[i]!=s2[j+1]){
            j=ne[j];
        }
        if(s2[i]==s2[j+1]){
            j++;
        }
        ne[i]=j;
    }
    cout<<m-ne[m];
}