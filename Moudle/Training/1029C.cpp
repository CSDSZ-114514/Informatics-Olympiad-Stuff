#include<bits/stdc++.h>
using namespace std;
long long h[1605];
long long tohash(string s){
    for(int i=1;i<=s.size();i++){
        h[i] = h[i - 1] * 131 + s[i - 1];
    }
    return h[s.size()];
}
int main(){

    return 0;
}