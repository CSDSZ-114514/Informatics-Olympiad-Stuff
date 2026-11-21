#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string inputs(){
	string temp;
	getline(cin,temp);
    for(int i=1;i<=temp.length();i++){
        temp[i-1]=tolower(temp[i-1]);
    }
	return ' '+temp+' ';
}
int main(){
        freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    s1=inputs();s2=inputs();
    //cout<<s1<<":"<<s2<<endl;
    //cout<<s2.find(s1);
    
    long long mem=0,cnt=0,pos=0;
    if(s2.find(s1)==-1){
        cout<<-1;
        return 0;
    }else{
        //cout<<s2.find(s1);
        pos=s2.find(s1);
        mem=pos;cnt++;
		pos+=s1.size()-1;
    }
    while (pos<s2.size()){
		pos=s2.find(s1,pos);
		if (pos==-1){
			break;
		}
		else{
			cnt++;
			pos=pos+s1.size()-1;
		}
	}
    cout<<cnt<<" "<<s2.find(s1);
    
    return 0;
}