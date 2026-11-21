#include<bits/stdc++.h>
using namespace std;
long long T;string s;
int main(){
    cin>>T;
    while(T--){
        cin>>s;
        long long sta=0,end=s.length()-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='l'||s[i]=='q'||s[i]=='b')sta++;
            else break;
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='l'||s[i]=='q'||s[i]=='b')end--;
            else break;
        }
        //cout<<sta<<" "<<end<<endl;
        if(sta>end)cout<<"Yes"<<endl;
        else{
            bool flag=true;
            string s1=s.substr(sta,end-sta+1);
            string s2=s1;reverse(s1.begin(),s1.end());//cout<<"s2:"<<s2<<endl;cout<<"s1:"<<s1<<endl;
            if(s1!=s2)flag=false;

            if(sta>s.length()-1-end)flag=false;
            else{
                string s3=s.substr(0,sta);
                reverse(s3.begin(),s3.end());
                if(s3!=s.substr(end+1,s3.length()))flag=false;//cout<<"n:"<<s.substr(end+1,s3.length())<<endl;
            }
            if(flag)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}