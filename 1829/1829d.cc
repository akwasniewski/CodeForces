//Gold Rush
//https://codeforces.com/contest/1829/problem/D
#include <iostream>
using namespace std;
bool Split(int pile, int& target){
    if(pile==target) return true;
    int left, right;
    left=pile*2/3;
    right=pile/3;
    if(left+right!=pile) return false;
    if(Split(left,target)) return true;
    if(Split(right,target)) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int starting, target;
        cin>>starting>>target;
        //its quick to implement but probably not optimal (but limits are huge hah)
        if(Split(starting, target)) cout<<"yes\n";
        else cout<<"no\n";
    }
}