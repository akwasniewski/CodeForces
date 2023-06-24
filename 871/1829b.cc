//blank space
//https://codeforces.com/contest/1829/problem/B
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int lenght;
        cin>>lenght;
        int count=0;
        int maxCount=0;
        for(;lenght; lenght--){
            bool element;
            cin>>element;
            if(!element){
                count++;
                if(count>maxCount) maxCount=count;
            }
            else{
                count=0;
            }
        }
        cout<<maxCount<<"\n";
    }
}