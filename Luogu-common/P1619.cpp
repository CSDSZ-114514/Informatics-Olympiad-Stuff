#include<bits/stdc++.h>
using namespace std;
map<long long, long long> m;
string str;
bool isprm(long long x){
    for(long long i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
void fj(long long x,bool& flag){
    bool dbf=x;
    for(long long i=2;i*i<=x;i++){
        while(x%i==0){
            x/=i;
            m[i]++;
            flag=true;
            //cout<<111111;
            if(dbf>4e7)return;
        }
    }
    if(x!=1){
        //cout<<x;
        if(x>=0&&x<=4e7){
            m[x]++;
        }
        
    }
}
int main(){
    bool flag=false;bool isfirst2=true;
    //for(long long i=0;i<=50;i++)cout<<notprime[i]<<" ";
    while(1){
        if(!isfirst2)cout<<endl;
        else isfirst2=false;
        cout<<"Enter the number="<<endl;
        flag=false;
        getline(cin,str);
        long long n=0;
        for(long long i=0;i<str.length();i++){
            if(str[i]>='0'&&str[i]<='9'){
                flag=true;
                n=n*10;
                n+=(str[i]-'0');
            }
        }
        //cout<<345678;
        if(!flag)break;
        //cout<<clock();
        m.clear();
        //cout<<clock();
        
        //cout<<345678;
        cout<<"Prime? ";
        bool ntp=false;
        //cout<<345678;
        //cout<<clock();
        if(n<=4e7){
        fj(n,ntp);
        }else{
            ntp=!isprm(n);
        }
        
        //cout<<clock();
        //cout<<clock();
        
        //cout<<ntp;
        //cout<<m.size()<<endl;
        if((ntp&&n!=2)||n<2){
            cout<<"No!"<<endl;
            if(n<2)continue;
            else if(n<=4e7){
                cout<<n<<"=";
                bool isfirst=true;
                //cout<<clock();
                while(m.size()){
                    if(!isfirst)cout<<"*";
                    else isfirst=false;
                    cout<<m.begin()->first<<"^"<<m.begin()->second;
                    m.erase(m.begin());
                }
                        
                //cout<<clock();
                cout<<endl;
            }else{
                cout<<"The number is too large!"<<endl;
                continue;
            }
        }else{
            cout<<"Yes!"<<endl;
            continue;
        }
    }
    return 0;
}