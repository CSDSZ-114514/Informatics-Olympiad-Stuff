#include<bits/stdc++.h>
using namespace std;
long long T;
long long pos1[100005],pos2[100005],c2[100000][3],c1[1000005][3];
int main(){
    cin>>T;
    while(T--){
        memset(pos1,0,sizeof(pos1));
        memset(pos2,0,sizeof(pos2));
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        long long n;
        long long cnt=0,ans=0,cnt1=0,cnt2=0;
        string s1,s2,t1,t2;
        cin>>n>>s1>>s2>>t1>>t2;
        s1=" "+s1;s2=" "+s2;
        t1=" "+t1;t2=" "+t2;
        for(int i=1;i<=n;i++){
            if(t1[i]!=t1[i-1]){
                pos1[i]=++cnt1;
            }else{
                pos1[i]=pos1[i-1];
            }
            c1[cnt1][s1[i]-'0']++;
        }
        for(int i=1;i<=n;i++){
            if(t2[i]!=t2[i-1]){
                pos2[i]=++cnt2;
            }else{
                pos2[i]=pos2[i-1];
            }
            c2[cnt2][s2[i]-'0']++;
        }
        // for(int i=0;i<=cnt1;i++){
        //     cout<<c1[i][1]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<=cnt1;i++){
        //     cout<<c2[i][1]<<" ";
        // }
        for(int i=1;i<=n;i++){
            if(t1[i]=='0'&&t2[i]=='0'){
                if(s1[i]==s2[i])ans++;
            }else if(t1[i]=='0'){
                if(c2[pos2[i]][s1[i]-'0']>0){
                    c2[pos2[i]][s1[i]-'0']--;
                    ans++;
                }     
            }else if(t2[i]=='0'){
                if(c1[pos1[i]][s2[i]-'0']>0){
                    c1[pos1[i]][s2[i]-'0']--;
                    ans++;
                } 
            }
        }
        for(int i=1;i<=n;i++){
            if(t1[i]=='0'||t2[i]=='0')continue;
            if(c1[pos1[i]][1]>0&&c2[pos2[i]][1]>0){
                c1[pos1[i]][1]--;c2[pos2[i]][1]--;
                ans++;
            }else if(c1[pos1[i]][0]>0&&c2[pos2[i]][0]>0){
                c1[pos1[i]][0]--;c2[pos2[i]][0]--;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}