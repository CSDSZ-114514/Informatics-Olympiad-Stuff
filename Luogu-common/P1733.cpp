#include<bits/stdc++.h>
using namespace std;
int main(){
    long long r = 1e9, l = 1;
    long long mid = (l + r) >> 1;
    while(l<=r){
        mid = (l + r) >> 1;
        long long res = 0;
        cout << mid << endl;
        cin >> res;
        if(res==0){
            return 0;
        }
        if(res==-1){
            l=mid+1;
        }
        if(res==1){
            r=mid-1;
        }
    }
    return 0;
}