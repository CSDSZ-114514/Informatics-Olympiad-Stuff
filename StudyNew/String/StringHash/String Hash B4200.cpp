#include<bits/stdc++.h>
using namespace std;
map<string ,int>m;
int main(){
    long long n;
    cin>>n;
    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        string tmp;
        for(int i=0;i<=str.size();i++){
            if(i==0||str[i]!=str[i-1]){
                tmp=tmp+str[i];
            }
        }
        m[tmp]++;
    }
    long long anss=-1e9;
    string ans;
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        if(anss<it->second){
            anss=it->second;
            ans=it->first;
        }
    }
    cout<<ans;

    return 0;
}