//The third letter
//https://codeforces.com/problemset/problem/1850/H
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct soldier{
    int color=0; //0-white //1-gray //2-white
    long long valOnEntry;
    vector<pair<int,int> >connections;
};
bool DFS(soldier soldiers[], int cur, long long curVal){
    soldiers[cur].valOnEntry=curVal;
    soldiers[cur].color=1;
    for(pair<int,int> con: soldiers[cur].connections){
        if(soldiers[con.first].color==0){
            if(DFS(soldiers, con.first, curVal+con.second)) return true;
        }
        else if(soldiers[con.first].color==1){
            if(curVal+con.second!=soldiers[con.first].valOnEntry) return true;
        }
    }
    soldiers[cur].color=2;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int soldierCount, conditionCount;
        cin>>soldierCount>>conditionCount;
        soldier soldiers[soldierCount];
        for(int i=0; i<conditionCount; i++){
            int a,b,d;
            cin>>a>>b>>d;
            soldiers[a-1].connections.push_back(make_pair(b-1,d));
            soldiers[b-1].connections.push_back(make_pair(a-1,-d));
        }
        bool hasBroken=false;
        for(int i=0; i<soldierCount; i++){
            if(soldiers[i].color==0 && DFS(soldiers, i, 0)){
                hasBroken=true;
                break;
            }
        }
        if(hasBroken) cout<<"NO\n";
        else cout<<"YES\n";
    }
}