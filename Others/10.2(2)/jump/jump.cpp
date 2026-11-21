#include<bits/stdc++.h>
using namespace std;
long long n,ts,tt,f[10005][5],ans=1e9,s,t;
struct DB{
    long long h,l,r,num;
}db[1000005];
bool cmp(DB x,DB y){
    if(x.h==y.h)return x.l<y.l;
    else return x.h>y.h;
}
int main(){
    cin>>n;
    cin>>ts>>tt;
    for(int i=1;i<=n;i++){
        cin>>db[i].l>>db[i].r>>db[i].h;
        db[i].num=i;f[i][0]=f[i][1]=1e9;
    }
    sort(db+1,db+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(db[i].num==ts){
            s=i;
            f[s][0]=0;
            f[s][1]=db[s].r-db[s].l;
        }
        if(db[i].num==tt)t=i;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<db[i].l<<" "<<db[i].r<<" "<<db[i].h<<endl;
    //     cout<<s;
    // }
    //cout<<f[s][1];
    
    for(int i=s;i<=t;i++){
        for(int j=i+1;j<=t;j++){
            if(db[i].l>=db[j].l&&db[i].l<=db[j].r&&db[i].h>db[j].h){ 				
                if(j==t){
                    ans=min(ans,f[i][0]+db[i].h-db[j].h);
                } 				
                f[j][0]=min({f[j][0],f[i][0]+db[i].l-db[j].l+db[i].h-db[j].h}); 				
                f[j][1]=min({f[j][1],f[i][0]+db[j].r-db[i].l+db[i].h-db[j].h}); 				
                break;
            }
        }
        for(int j=i+1;j<=t;j++){
			if(db[i].r>=db[j].l&&db[i].r<=db[j].r&&db[i].h>db[j].h){
				if(j==t){
                    ans=min(ans,f[i][1]+db[i].h-db[j].h);
                }
				f[j][0]=min({f[j][0],f[i][1]+db[i].r-db[j].l+db[i].h-db[j].h});
				f[j][1]=min({f[j][1],f[i][1]+db[j].r-db[i].r+db[i].h-db[j].h});
				break;
			}
		}
    }
    if(ans==1e9){
        cout<<"-1";
    }else{
        cout<<ans;
    }

    return 0;
}