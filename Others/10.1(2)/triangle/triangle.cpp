#include<bits/stdc++.h>
using namespace std;
string trg,trgg[5],trgu,trgl,trgr;
int main() {
	cin>>trg;
	if(trg[trg.size()-1]=='4') {
		cout<<trg.substr(0,trg.size()-1)<<1<<endl;
        cout<<trg.substr(0,trg.size()-1)<<2<<endl;
        cout<<trg.substr(0,trg.size()-1)<<3;
		return 0;
	}
	for(int i=1; i<=trg.size()-1; i++) {
		if(trg[i]=='1'){
            trgg[0]=trg.substr(0,i)+"4";
        }
		else if(trg[i]=='2'){
            trgg[1]=trg.substr(0,i)+"4";
        }	
		else if(trg[i]=='3'){
            trgg[2]=trg.substr(0,i)+"4";
        }	
	}
	sort(trgg,trgg+3); 
	for(int i=0;i<=2;i++){
        if(trgg[i][0]=='T'){
            cout<<trgg[i]<<endl;
        }
    }
	return 0;
}
