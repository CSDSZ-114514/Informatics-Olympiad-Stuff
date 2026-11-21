#include<bits/stdc++.h>
using namespace std; 
map<string ,long long> m,vis;
string str[20005];
long long n;
bool cmp(string a,string b){
    if(a.size()==b.size()){
        return a<b;
    }else{
        return a.size()<b.size();
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i];
    }
    sort(str+1,str+1+n,cmp);
    long long ans=0;
    for(int i=1;i<=n;i++){
        vis.clear();
        for(int j=0;j<str[i].size();j++){
            for(int k=j;k<str[i].size();k++){
                string s=str[i].substr(j,k-j+1);
                if(vis[s])continue;
                ans+=m[s];
                vis[s]=1;
            }
        }
        ans+=m[str[i]];
        m[str[i]]++;

    }
    cout<<ans;
    //system("pause");
    return 0;
}