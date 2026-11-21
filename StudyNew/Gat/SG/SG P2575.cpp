#include<bits/stdc++.h>
using namespace std;
long long T;long long n,m,p[100005],t[25];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        long long res=0;
        for(int i=1;i<=n;i++){
            memset(t,0,sizeof(t));
            cin>>m;
            for(int j=1;j<=m;j++){
                cin>>p[j];
                t[p[j]]=1;
            }
            long long cnt=0,cnt2=20-m;
            for(int i=1;i<=20;i++){
                if(t[i]){
                    cnt++;
                }else{
                    if(cnt2%2==1){
                        res^=cnt;cnt=0;
                    }else{
                        cnt=0;
                    }
                    cnt2--;
                }
            }
        }
        
        
        cout<<(res!=0?"YES":"NO")<<endl;

    }
}