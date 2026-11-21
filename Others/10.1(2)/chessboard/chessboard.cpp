#include<bits/stdc++.h>
using namespace std;
long long n1,m1,n2,m2,k;
long long mp[1005][1005];
int main(){
    cin>>n1>>m1>>n2>>m2>>k;
    long long num=0,sum=0,bow=0,nbow=0;
    for (int i=1;i<=n1;i++)
        for (int j=1;j<=m1;j++) {
            cin>>num;
            bow=((i+j)%2)?1:-1;
            if (num==999999)
                nbow = bow;
            else
                sum+=bow*(num-k);
        }
    for (int i=1;i<=n2;i++)
        for (int j=1;j<=m2;j++) {
            cin >>num;
            bow =((i+j+n1)%2)?1:-1;
            if (num==999999)
                nbow=bow;
            else
                sum+=bow*(num-k);
        }
    cout << k-sum*nbow;
    //system("pause");
    return 0;
}