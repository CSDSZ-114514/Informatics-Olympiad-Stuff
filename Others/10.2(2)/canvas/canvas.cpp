#include<bits/stdc++.h>
using namespace std;
long long cnt=-1;
const long long N=1e5+5;
long long T;
long long n,m,k,a[N],ans=0;
int main(){
    cin>>T;
	while(T--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=2;i<n;i++){
            if(m==0){
                break;
            }
            if(a[i]==a[i-1]&&a[i]==a[i+1]){
                m--;
                a[i]=N;
            }
        }
        for(int i=2;i<=n;i++){
            if(m==0){
                break;
            }
            if(a[i]==a[i-1]){
                m--;
                a[i]=N;
            }
        }
        long long ans=1;
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1]){
                ans++;
            }
        }
        cout<<ans<<endl;	
	}
	return 0;
} 
