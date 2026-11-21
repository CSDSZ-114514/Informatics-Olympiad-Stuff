#include<bits/stdc++.h>
using namespace std;
string str1,str2;
long long ans;
int main(){
    cin>>str1>>str2;
	for(int i=0;i<str1.size();i++){
        if(str1[i]!=str2[i]){
            if(str2[i]=='o'){
                str2[i]='*';
            }else{
                str2[i]='o';
            }
            if(str2[i+1]=='o'){
                str2[i+1]='*';
            }else{
                str2[i+1]='o';
            }
		    ans++;
	    }
    }
    cout<<ans;
    //system("pause");
    return 0;
}

