#include <iostream>
using namespace std;
int main(){
    int s;
    cin>>s;
    for(;s>0;s--){
        bool arr[49]={false};
        int length;
        string word;
        cin>>length>>word;
        char last=word[0];
        for(int i=1; i<length; i++){
            char cur=word[i];
            char hash=(last-97)*7+(cur-97);
            arr[hash]=true;
            last=cur;
        }
        int count=0;
        for(int i=0; i<49; i++){
            if(arr[i])count++;
        }
        cout<<count<<"\n";
    }
}