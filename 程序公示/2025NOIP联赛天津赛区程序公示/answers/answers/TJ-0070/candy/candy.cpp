#include <bits/stdc++.h>
using namespace std;
//======debug======
const bool debug = debug;
int suojin = 0;
//=================
const int MAXN = 1e5 + 5;
const long long MAXM = 1e18+5;
int n,xy[MAXN][3],res,sum[MAXN];
int xory[MAXN] = {0};//0 for x,1 for y;
long long m;

vector<int> path;
void dfs(int sum,bool stop,int cnt,int choose = n){

    xory[choose] = 1-xory[choose];
    if(stop){
        if(cnt > res&&debug){
            for(int i:path){
                cout << i <<' ';
            }
            cout << endl;
        }
        res = max(res,cnt);
        return;
    }
    for(int i=0;i<n;i++){
        if(sum+xy[i][xory[i]]<=m){
            path.push_back(xy[i][xory[i]]);
            dfs(sum+xy[i][xory[i]],false,cnt+1,i);
            path.pop_back();
            xory[i] = 1-xory[i];
        }
        if(sum+xy[i][xory[i]]>m){
            dfs(sum,true,cnt,n);
        }
    }
}//already debugged
bool checka(){
    for(int i=0;i<n;i++){
        if(xy[i][0]!=xy[i][1])
            return false;
    }
    return true;
}
bool checkb(){
    for(int i=0;i<n;i++){
        if(xy[i][0]<xy[i][1])
            return false;
    }
    return true;
}
priority_queue<int,vector<int>,greater<int> > pq;
queue<int> q;

int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> xy[i][0] >> xy[i][1];
        xy[i][2]=xy[i][1]+xy[i][0];
    }
    
    if(n<=10){
        dfs(0,false,0);
        cout << res << '\n';
        return 0;
    }//already debugged
    
    if(checka()){
        int mini = 1e9+5;
        for(int i=0;i<n;i++){
            mini = min(mini,xy[i][0]);
        }
        res = m/mini;
        cout << res;
        return 0;
    }//already debugged

    if(checkb()){
        int minpair = 1e9*2+5;
        for(int i=0;i<n;i++){
            minpair=min(minpair,xy[i][2]);
            cout << i <<' '<<xy[i][2]<<' '<<minpair<<endl;
        }
        res = (m/minpair)*2;
        int minfirst = 1e9*2+5;
        for(int i=0;i<n;i++){
            minfirst = min(minfirst,xy[i][0]);
        }
        m %= minpair;
        if(m>=minfirst){
            res++;
        }
        cout << res;
        return 0;
    }
}





























