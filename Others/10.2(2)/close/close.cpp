#include<bits/stdc++.h>
using namespace std;
long long n,t,k;
string str;
bool check(long long q){
    string str1=str;long long cnt=0;//cout<<str1<<endl;
    for(int i=0;i<str1.length();i++){
        if(str1[i]=='1'){
            cnt++;
            for(int j=0;j<q;j++){
                str1[i+j]='0';
            }
        }
    }
    if(cnt<=k)return true;
    else return false;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>str;
        long long l=1,r=n;
        while(l<r){
            long long mid=(l+r)>>1;
            //cout<<mid<<endl;
            if(check(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<r<<endl;
        //check(1);
        //cout<<check(1)<<endl;
    }
}
