#include<bits/stdc++.h>
using namespace std;
set<long long> s;
long long n,x=0,pet=0,peo=0,a,ans;
int main(){
    s.insert(-INT_MAX);
    s.insert(INT_MAX);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>x;
        if(a==0){
            pet++;
            if(pet>peo){
               s.insert(x);
            }else{
                int pre= *(--s.lower_bound(x));
                int nx=*(s.lower_bound(x));
                if(pre==-INT_MAX){
                    s.erase(nx);
                    ans+=nx-x;
                }else if(nx==INT_MAX){
                    s.erase(pre);
                    ans+=x-pre;
                }else{
                    if(nx-x<x-pre){
                        s.erase(nx);
                        ans+=nx-x;
                    }else{
                        s.erase(pre);
                        ans+=x-pre;
                    }
                }
            }
        }
        if(a==1){
            peo++;
            if(pet<peo){
               s.insert(x);
            }else{
                int pre= *(--s.lower_bound(x));
                int nx=*(s.lower_bound(x));
                if(pre==-INT_MAX){
                    s.erase(nx);
                    ans+=nx-x;
                }else if(nx==INT_MAX){
                    s.erase(pre);
                    ans+=x-pre;
                }else{
                    if(nx-x<x-pre){
                        s.erase(nx);
                        ans+=nx-x;
                    }else{
                        s.erase(pre);
                        ans+=x-pre;
                    }
                }
            }
        }
    }
    cout<<ans%1000000;
    return 0;
}