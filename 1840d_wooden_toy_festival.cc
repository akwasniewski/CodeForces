#include <iostream>
#include <algorithm>
using namespace std;
//value binsary search
bool IsPossible(int data[], int count, int val){
    int cur=0;
    int ref=data[0]+val;
    for(int i=0; i<count; i++){
        if(cur==3) return false;
        if(data[i]-ref>val){
            ref=data[i]+val;
            cur++;
        }
    }
    if(cur==3) return false;
    return true;
}
int ValueBinSearch(int data[], int count){
    if(IsPossible(data,count,0)) return 0;
    int r=1;
    while(!IsPossible(data,count,r)){
        r*=2;
    }
    if(r==1) return 1;
    int l=r/2;
    int m=(l+r)/2;
    while(r-l>1){
        if(IsPossible(data,count,m)){
            r=m;
            m=(l+r)/2;
        }
        else{
            l=m;
            m=(l+r)/2;
        }
    }
    if(IsPossible(data,count,l)) return l;
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int clientCount;
        cin>>clientCount;
        int requests[clientCount];
        for(int i=0; i<clientCount; i++){
            cin>>requests[i];
        }
        sort(requests, requests+clientCount);
        cout<<ValueBinSearch(requests, clientCount)<<"\n";
    }
}