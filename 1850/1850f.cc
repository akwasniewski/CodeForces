//We were both children
//https://codeforces.com/problemset/problem/1850/F
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int frogCount;
        cin>>frogCount;
        unordered_map<int, int> frogHops;
        for(int i=0; i<frogCount; i++){
            int hop;
            cin>>hop;
            if(hop<=frogCount){
                frogHops.emplace(hop, 0);
                frogHops[hop]++;
            }
        }

        int catchCount[frogCount];
        for(int i=0; i<frogCount; i++) catchCount[i]=0;
        for(pair<int,int> curHop: frogHops){
            int curPos=curHop.first;
            while(curPos<=frogCount){
                catchCount[curPos-1]+=curHop.second;
                curPos+=curHop.first;
            }
        }
        cout<<*max_element(catchCount, catchCount+frogCount)<<"\n";
    }
}