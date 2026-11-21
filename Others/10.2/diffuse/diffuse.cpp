#include<bits/stdc++.h>
using namespace std;
struct POINT{
    long long x,y;
}pt[1005];
long long fa[1005];long long n;
int find(int x){
	if(fa[x] == x) return x; 
	else return find(fa[x]); 
}
void heb(long long x,long long y){
    x = find(x), y = find(y); 
	fa[x] = y; 
}

bool check(long long t){
    for(int i=1;i<=n;++i){
        fa[i]=i; //cout<<fa[i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(find(i)==find(j))continue;
            // if(t==24){
            //     cout<<i<<" "<<j<<" "<<abs(pt[i].x-pt[j].x)+abs(pt[i].y-pt[j].y)<<endl;
            // }
            //cout<<t<<endl;
            
            if(abs(pt[i].x-pt[j].x)+abs(pt[i].y-pt[j].y)<=2*t){
                if(find(i)!=find(j)){
                    heb(i,j);
                }
            }
        }
    }
    // if(t==24){
    //     for(int i=1;i<=n;i++){
    //         cout<<fa[i]<<" ";
    //     }
    // }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i)cnt++;
    }
    //if(t==24)cout<<t<<":"<<cnt<<endl;
    if(cnt>1){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    freopen("diffuse.in","r",stdin);
    freopen("diffuse.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>pt[i].x>>pt[i].y;
    }
    long long l=0,r=2e9;
    while(l<r){
        long long mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<r;
    return 0;
}