#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int problemCount, maxDifference;
        cin>>problemCount>>maxDifference;
        int difficulties[problemCount];
        for(int i=0; i<problemCount; i++){
            cin>>difficulties[i];
        }
        sort(difficulties, difficulties+problemCount);
        int first=0;
        int maxLen=1;
        int curLen=1;
        for(int i=1; i<problemCount; i++){
            if(difficulties[i]-difficulties[i-1]>maxDifference){
                curLen=0;
            }
            curLen++;
            if(curLen>maxLen){
                maxLen=curLen;
            }
        }
        
        cout<<problemCount-maxLen<<"\n";
    }
}