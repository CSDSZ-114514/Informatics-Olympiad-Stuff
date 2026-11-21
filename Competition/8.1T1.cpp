#include<bits/stdc++.h>
using namespace std;
string s,ans;
int main(){
    cin >> s;
    for (int i = 1;;i++){
        long long l = s.size() - (i - 1);
        if(l<=0)
            break;
        if(i%2==1){
            ans += s.substr(0, l);
        }else{
            string s1 = s.substr(s.size() - l, l);
            reverse(s1.begin(), s1.end());
            ans += s1;
        }
    }
    cout << ans;
    return 0;
}