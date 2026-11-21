#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005];
deque<long long> deq;
void dddl(){
    for(int i=1;i<=n;i++){
        // if(i<=k){
        //     deq.push_back(i);
        // }
        if(!deq.empty()&&deq.front()<i-k+1){
            deq.pop_front();
        }
        while(!deq.empty()&&a[deq.back()]>a[i]){
            deq.pop_back();
        }
        deq.push_back(i);
        if(i<k)continue;
        cout<<a[deq.front()]<<" ";
    }
    cout<<endl;
    while(!deq.empty()){
        deq.pop_front();
    }
    for(int i=1;i<=n;i++){
        // if(i<=k){
        //     deq.push_back(i);
        // }
        if(!deq.empty()&&deq.front()<i-k+1){
            deq.pop_front();
        }
        while(!deq.empty()&&a[deq.back()]<a[i]){
            deq.pop_back();
        }
        deq.push_back(i);
        if(i<k)continue;
        cout<<a[deq.front()]<<" ";
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dddl();
}