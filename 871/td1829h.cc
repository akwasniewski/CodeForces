//unfinished
#include <iostream>
using namespace std;
int CountOnBits(short cur){
    int count=0;
    while(cur){
        count++;
        cur=cur>>1;
    }
    return cur;
}
long long quickPower(long long base, int exponent) {
    if (exponent == 0)
        return 1;
    
    long long result = 1;    
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result *= base;
        base *= base;
        exponent /= 2;
    }
    return result;
}
long long CleanUpMap(std::unordered_map<short, long long>& map, int onBits) {
    long long countEqual=0;
    auto it = map.begin();
    while (it != map.end()) {
        int bitCount=CountOnBits(it->second);
        if(bitCount==onBits){
            countEqual+=quickPower(2,it->first)-1;
        }
        if (it->second == 0 || bitCount<=onBits) {
            it = map.erase(it);
        } else {
            ++it;
        }
    }
    return countEqual;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int arrayLength, onBits;
        cin>>arrayLength>>onBits;
        unordered_map<short, long long> counts;
        for(int i=0; i<64; i++){
            counts.insert({i,0});
        }
        for(int i=0; i<arrayLength; i++){
            short cur;
            cin>>cur;
            counts[cur]++;
        }
        long long count=CleanUpMap(counts, onBits);
        for(auto cur: counts){
            cout<<"{"<<cur.first<<","<<cur.second<<"} ";
        }
        cout<<endl;
        cout<<"count "<<count<<endl;
    }
}