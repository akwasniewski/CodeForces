//Word on the paper
//https://codeforces.com/problemset/problem/1850/C
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        string word="";
        for(int i=0; i<8; i++){
            string line;
            cin>>line;
            for(int i=0; i<8; i++){
                if(line[i]!='.'){
                    word+=line[i];
                }
            }
        }
        cout<<word<<"\n";
    }
}