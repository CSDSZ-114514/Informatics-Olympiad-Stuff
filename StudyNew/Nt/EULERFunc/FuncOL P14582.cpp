#include<bits/stdc++.h>
using namespace std;
long long m,k;
bool sp[15];
long long phi[10000005];
long long getphi(long long n){
    long long res=n;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0){
            res=res/i*(i-1);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1){
        res=res/n*(n-1);
    }
    return res;
}
int main(){
    long long T;
    cin>>T;
    while(T--){
        cin>>m>>k;
        long long a;long long cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=10;i++){sp[i]=0;} 
        for(int i=1;i<=k;i++){cin>>a;sp[a]=1;}
        if(k==9){
            cout<<-1<<endl;continue;
        }
        for(int i=1;i<10;i++){
            if(!sp[i]){
                cnt3=i;break;
            }
        }
        while(m%2==0){
            m/=2;cnt1++;
        }
        while(m%5==0){
            m/=5;cnt2++;
        }
        long long s=getphi(9*m);
        cout<<min(max(cnt1,cnt2),(long long)1)+1<<endl;
        cout<<cnt3<<" "<<s<<endl;
        if(max(cnt1,cnt2)==0)continue;
        cout<<0<<" "<<max(cnt1,cnt2)<<endl;
    }
    return 0;
}