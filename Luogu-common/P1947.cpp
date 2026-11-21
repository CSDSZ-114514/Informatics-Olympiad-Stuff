extern "C" int Seniorious(int);   
extern "C" int Chtholly(int n,int c){
    long long r = n, l = 1;
    long long mid = (l + r) >> 1;
    while(l<=r){
        mid = (l + r) >> 1;
        long long res= Seniorious(mid);
        
        if(res==0){
            return mid;
        }
        if(res==-1){
            l=mid+1;
        }
        if(res==1){
            r=mid-1;
        }
    }
    return mid;
}