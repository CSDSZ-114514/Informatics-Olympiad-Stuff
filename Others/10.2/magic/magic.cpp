#include<bits/stdc++.h>
using namespace std;
long long n,k,e[15];
struct PP{
    long long num,w;
}p[100005];
bool cmp(PP a,PP b){
    if(a.w==b.w) return a.num<b.num;
    return a.w>b.w;
}
int main(){
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=10;i++){
        cin>>e[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i].w;
        p[i].num=i;
    }
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++){
        p[i].w+=e[((i-1)%10+1)];
    }
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=k;i++){
        cout<<p[i].num<<" ";
    }

    //system("pause");
    return 0;
}
