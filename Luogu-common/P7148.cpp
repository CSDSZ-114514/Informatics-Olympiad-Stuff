#include<bits/stdc++.h>
using namespace std;
long long n,ans;
vector<long long> e[100005];
void dg(long long x,long long fa){
    long long so=0;
    for(long long t:e[x]){
        if(t!=fa){
            so++;
            dg(t,x);
            ans+=1;
        }
    }
    for(int i=1;i<=20;i++){
        if(pow(2,i)>so&&so!=0){
            ans+=i;
            break;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        long long a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dg(1,1);
    cout<<ans;
    
    return 0;
}