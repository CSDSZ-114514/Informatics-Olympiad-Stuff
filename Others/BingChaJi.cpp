#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long fa[1000005];
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
long long find(long long s){
    if(fa[s]==s){
        return s;
    }else{
        return fa[s]=find(fa[s]);
    }
}
long long heb(long long a,long long b){
    fa[find(a)]=find(b);
    return 0;
}
int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        long long z,x,y;
        cin>>z>>x>>y;
        if(z==1){
            heb(x,y);
        }else{
            if(find(x)==find(y)){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }
    return 0;
}