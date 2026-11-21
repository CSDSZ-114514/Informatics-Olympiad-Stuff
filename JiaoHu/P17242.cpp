#include<bits/stdc++.h>
using namespace std;
int n,m;
set<pair<int,pair<int,int>>>st[4];
void init(int N,int M){
    n=N,m=M;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            st[0].insert({i+j,{i,j}});
            st[1].insert({i-j,{i,j}});
            st[2].insert({-i+j,{i,j}});
            st[3].insert({-i-j,{i,j}});
        }
    }
}
pair<int,int> receive_block(int TL,int TR,int BL,int BR){
    pair<int,int>res;
    if(!BR) res=(*st[0].begin()).second;
    else if(!BL) res=(*st[1].begin()).second;
    else if(!TR) res=(*st[2].begin()).second;
    else res=(*st[3].begin()).second;
    pair<int,int> [i,j]=res;
    st[0].erase({i+j,{i,j}});
    st[1].erase({i-j,{i,j}});
    st[2].erase({-i+j,{i,j}});
    st[3].erase({-i-j,{i,j}});
    return make_pair(i<<1,j<<1);
}
