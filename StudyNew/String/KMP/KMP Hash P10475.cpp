#include<bits/stdc++.h>
using namespace std;
long long r,c;
const long long N=1e5+5;
const unsigned long long hs1=131,hs2=13331;
unsigned long long p[N];
unsigned long long buc[N],hr[N],hc[N];
unsigned long long ner[N],nec[N];
char mp[10005][80];
int main(){
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        unsigned long long ans=0;
        for(int j=1;j<=c;j++){
            ans=ans*hs1+mp[i][j];
        }
        hr[i]=ans;
    }
    for(int i=1;i<=c;i++){
        unsigned long long ans=0;
        for(int j=1;j<=r;j++){
            ans=ans*hs1+mp[j][i];
        }
        hc[i]=ans;
    }
    for(int i=2,j=0;i<=r;i++){
        while(j&&hr[i]!=hr[j+1]){
            j=ner[j];
        }
        if(hr[i]==hr[j+1]){
            j++;
        }
        ner[i]=j;
    }
    for(int i=2,j=0;i<=c;i++){
        while(j&&hc[i]!=hc[j+1]){
            j=nec[j];
        }
        if(hc[i]==hc[j+1]){
            j++;
        }
        nec[i]=j;
    }
    cout<<(r-ner[r])*(c-nec[c]);

    return 0;
}