#include<bits/stdc++.h>
using namespace std;
long long n,st[1000005],ans,sum[1000005];
deque<long long> q;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>st[i],st[i+n]=st[i];
    for(int i=1;i<=2*n;i++)sum[i]=sum[i-1]+st[i];
    for(int i=1; i<=2*n; i++) {
        while(!q.empty()&&sum[i]<sum[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
        if(q.front() < i-n+1) {
            q.pop_front();
        }

        if(i>n){
            //cout<<sum[q.front()]<<":"<<sum[i+1-n]<<endl;
            if(sum[q.front()]-sum[i+1-n]>=0)ans++;
        }
    }
    cout<<ans;
    return 0;
}