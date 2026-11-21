
/*
int tmp = x;
x = y
y = tmp-(a/b)*y
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

int a[100005],b[100005],c[100005],s[100005];

signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    int mc = LONG_MAX;

    for (int i = 1;i<=n;i++){
        cin>>a[i]>>b[i];
        c[i] = a[i]+b[i];
        mc = min(mc,c[i]);
    }

    sort(a+1,a+n+1);

    int sum = 0,ans = m/mc*2,cnt = 0;
    
    for (int i = 1;i<=n;i++){
    	s[i] = s[i-1] + a[i];	
    	if (s[i]>m){
    		s[i] == 0;
    		break;
		} 
	}
    
    for (int i = 1;i<=n;i++){
        //xuan
//        int nw = (m-sum-a[i]) / mc * 2 + cnt + 1;
//        if (nw>=ans){
//            ans = nw;
//            sum += a[i];
//            cnt++;
//        }
//        else {
//            break;
//        }
		if (s[i] == 0)break;
		ans = max(ans,(m-s[i]) / mc * 2 + i);
    }
    
    
//	
//	if (sum + a[cnt+1] <= m){
//		
//	}ans = max(ans,(m-sum-a[cnt+1])/mc*2 + cnt + 1);
//	
    cout<<ans;

    return 0;
}
