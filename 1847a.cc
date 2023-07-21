//The Man who became a God
//https://codeforces.com/problemset/problem/1847/A 
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0; s--){
        int villagerCount, groupCount;
        cin>>villagerCount>>groupCount;

        int villagerSuspicions[villagerCount];
        bool isFirstInGroup[villagerCount];

        auto comp = [](pair<int,int> a, pair<int,int> b){
            return a.second<b.second;
        };

        priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(comp)> que(comp);
        int curSum=0;

        for(int i=0; i<villagerCount; i++){
            isFirstInGroup[i]=false;
            cin>>villagerSuspicions[i];

            if(i==0){
                que.push(make_pair(0, 0));
            }

            else{
                int curVal=abs(villagerSuspicions[i]-villagerSuspicions[i-1]);
                curSum+=curVal;
                que.push(make_pair(i, curVal));
            }
        }

        int curGroups=1;

        for(; curGroups<groupCount; curGroups++){
            pair<int, int> cur=que.top();
            que.pop();
            isFirstInGroup[cur.first]=true;
            curSum-=cur.second;
        }
        cout<<curSum<<"\n";
    }
}
