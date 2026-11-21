#include<bits/stdc++.h>
using namespace std;
long long t;
long long fa[30005];long long n,qzh[30005],qun[30005];
// int find(int x){
// 	if(fa[x] == x) return x; 
// 	else return find(fa[x]); 
// }
int find(int x){                                      
    if(fa[x]==x)return fa[x];
    int fn=find(fa[x]);                                  
    qzh[x]+=qzh[fa[x]];                
    return fa[x]=fn;
}
void heb(long long x,long long y){
    x = find(x); y=find(y);
	fa[x] = y; 
    qzh[x]+=qun[y];
    qun[y]+=qun[x];
    qun[x]=0;
}
int main(){
    cin>>t;
    for(int i=1;i<=30000;++i){
        fa[i]=i; //cout<<fa[i]<<" ";
        qun[i]=1;
    }
    for(int i=1;i<=t;i++){
        //cout<<1;
        char s;long long a,b;
        cin>>s>>a>>b;
        if(s=='M'){
            //cout<<2;
            heb(a,b);
        }else{
            //cout<<3;
            long long c=0;
            long long a1=a,b1=b;
            if(find(a)!=find(b))cout<<-1<<endl;
            else cout<<abs(qzh[a]-qzh[b])-1<<endl;
        }
    }
}