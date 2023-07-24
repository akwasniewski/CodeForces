#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int responseCount;
        cin>>responseCount;
        int maxQuality=-1;
        int whereMax;
        for(int i=0;i<responseCount; i++){
            int wordCount, quality;
            cin>>wordCount>>quality;
            if(wordCount<=10){
                if(quality>maxQuality){
                    maxQuality=quality;
                    whereMax=i+1;
                }
            }
        }
        cout<<whereMax<<"\n";
    }
}