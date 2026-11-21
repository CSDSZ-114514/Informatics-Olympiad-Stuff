#include<bits/stdc++.h>
using namespace std;
long long n,l,r,a[1000005];
int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    cin>>n;long long maxr=0;
    for(int i=1;i<=n;i++){
        cin>>l>>r;maxr=max(r,maxr);
        a[l]++;a[r]--;
    }
    long long pp=0,cnt=0,ans1=0,ans2=0;
    for(int i=1;i<=maxr+1;i++){
        //cout<<a[i];
        //cout<<pp<<" ";
        if(pp==0&&cnt>=0){
            cnt++;//cout<<333;
        }else if(pp>0&&cnt<=0){
            cnt--;//cout<<222;
        }else if(pp==0&&cnt<0){
            //cout<<111;
            ans1=max(-1*cnt,ans1);
            cnt=0;
        }else if(pp>0&&cnt>0){
            //cout<<444;
            ans2=max(cnt,ans2);
            cnt=0;
        }
        pp+=a[i];
    }
    cout<<ans1+1<<" "<<ans2;
    return 0;
}