#include<bits/stdc++.h>
using namespace std;
long long n,s,v[100005],eg[100005],cnt;bool q[100005],brk[100005];
int main(){
    
	freopen("cannonball.in","r",stdin);
	freopen("cannonball.out","w",stdout);
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>q[i]>>v[i];
    }
    long long eng=1;
    while(s>=1&&s<=n){
        //cout<<s<<" ";
        if(q[s]){
			//cout<<abs(eng)<<" "<<v[s]`<<endl;
            if(!brk[s]&&v[s]<=abs(eng)){
                brk[s]=1;cnt++;
            }
        }else{
            if(eng<0){
                eng-=v[s];
            }else{
                eng+=v[s];
            }
            eng*=-1;
			if(v[s]==0){
				if(eg[s]==eng){
					break;
				}else{
					eg[s]=eng;
				}
			}
        }
		s+=eng;
		if(eng==0){
			break;
		}
    }
    cout<<cnt<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<brk[i];
//	}
}
