#include<bits/stdc++.h>
using namespace std;
map<string ,long long >m[10005];
bool vis[10005];
long long n,minn,maxn;
int main(){
    cin>>n>>minn>>maxn;
    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        if(str.size()<minn){
            m[i][str]++;
        }else{
            for(int j=minn;j<=min(maxn,(long long)str.size());j++){
                for(int k=0;str.size()-k+1>j;k++){
                    m[i][str.substr(k,j)]++;
                }
            }
        }
    }
    cin>>str;long long ans=0;
    if(str.size()>=minn){
        for(int j=minn;j<=min(maxn,(long long)str.size());j++){
            for(int k=0;str.size()-k+1>j;k++){
                for(int i=1;i<=n;i++){
                    if(m[i][str.substr(k,j)]!=0&&!vis[i]){
                        ans++;
                        vis[i]=true;
                    }
                }
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(m[i][str]!=0&&!vis[i]){
                ans++;
                vis[i]=true;
            }
        }
    }
    
    cout<<ans;
    return 0;
}