#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
   int n;
   cin>>n;
   int a[50009];
   for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    int q;
    cin>>q;
    long long b[50009];
    long long sum=0;
    while(q--){
       int l,r;
       cin>>l>>r;
       for(int i=0;i<n;i++){
        b[i]=-1e18;
       }
       for(int i=0;i<n;i++){
          for(int j=i+l-1;j<=i+r-1&&j<n;j++){
          sum=0;
              for(int k=i;k<=j;k++){
                 sum+=a[k];
              }
              for(int k=i;k<=j;k++){
                 b[k]=max(b[k],sum);
              }
          }
       }
       unsigned long long aa=0,bb=0;
       for(int i=0;i<n;i++){
          bb=i+1;
          bb*=b[i];
          //cout<<bb<<' ';
          aa=aa^bb;
       }
       cout<<aa<<endl;
    }
    return 0;
}
