#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MAXN = 1e5;
const long long MAXM = 1e18;
int n,un = 0,cnt = 0;long long m;
//part score(5/7) => about 50score

struct candy{
    int x,y,sum;
    bool status = 0;
    candy(){}
    candy(int x,int y):x(x),y(y),sum(x+y){}
    void next(){this->status=!this->status;}
    int now(){return this->status?this->y:this->x;}
};
candy candys[MAXN];

bool comp_sum(candy l,candy r){
    return l.sum<r.sum;
}
bool comp_now(candy l,candy r){
    return l.now()<r.now();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin >> n >> m;
    int mm = 1e9,x,y,ms = 2e9;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        if(mm<=min(x,y))continue;
        candys[un] = candy(x,y);
        mm = min(mm,max(x,y));
        un++;
    }
    //double eat
    // << un << endl;//2
    sort(candys,candys+un,comp_sum);
    //cout << candys[0].sum << candys[1].sum << endl;//56
    long long t = m/candys[0].sum;
    if(candys[0].x<candys[0].y)--t;//behind is bigger so we may won't eat it
    if(t<0)t=0;
    cnt += t*2;
    m -= t*candys[0].sum;
    //cout << cnt << endl;//4
    //eat
    bool run = 1;
    while(run){
        run = 0;
        sort(candys,candys+un,comp_now);
        if(m>=candys[0].now()){
            ++cnt;
            m -= candys[0].now();
            candys[0].next();
            run = 1;
        }
    }
    cout << cnt;

    return 0;
}
























