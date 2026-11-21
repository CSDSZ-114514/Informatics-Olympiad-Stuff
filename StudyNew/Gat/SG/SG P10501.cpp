#include<bits/stdc++.h>
using namespace std;
long long w,h;
long long sg[1005][1005];
long long getsg(long long u,long long v){
    if(sg[u][v]!=-1)return sg[u][v];
    set<long long> s;
    for(int i=2;i<=u-2;i++)s.insert(getsg(i,v)^getsg(u-i,v));
    for(int i=2;i<=v-2;i++)s.insert(getsg(u,i)^getsg(u,v-i));
    for(int i=0;;i++)if(s.count(i)==0){sg[u][v]=i;return i;}
}
int main(){
    while(cin>>w>>h){
        memset(sg,-1,sizeof(sg));
        cout<<(getsg(w,h)!=0?"WIN":"LOSE")<<endl;
    }    
    return 0;
}