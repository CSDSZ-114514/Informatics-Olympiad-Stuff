#include<bits/stdc++.h>
using namespace std;
long long n, m;
set<long long> se;
stack<long long> st;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        char d;
        cin >> d;
        long long x;
        se.insert(0);
        se.insert(n+1);
        if(d=='R'){
            x = st.top();
            st.pop();
            se.erase(x);
        }
        if(d=='D'){
            cin >> x;
            se.insert(x);
            st.push(x);
        }
        if(d=='Q'){
            cin >> x;
            if(se.find(x)!=se.end()){
                cout << 0 << endl;
                continue;
            }
            auto p = se.upper_bound(x);
            auto p1 = p;
            p1--;
            cout << (*p) -(*p1)-1<<endl;
        }
    }
        return 0;
}