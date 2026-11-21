#include<bits/stdc++.h>
using namespace std;
namespace Main{
int a;
FILE *fpi;
using lnt=long long;
long long randL(){
    return lnt(rand())<<32|lnt(rand())<<16|lnt(rand());
}
void main(){
    string name="sale",inpn=name+".in",oupn=name+".out",ansn=name+".ans",prog=name+".exe";
    while(true){
        fpi=fopen("sale.in","w");
        int n=rand()%10+1,m=2;
        fprintf(fpi,"0 1\n%d %d\n",n,m);
        for(int i=1;i<=n;i++){
            fprintf(fpi,"%d ",rand()%10);
        }
        system(name.c_str());
        //if(system(("fc "+oupn+" "+ansn).c_str()))break;
    }
}
}
signed main(){
    Main::main();
    return 0;
}
