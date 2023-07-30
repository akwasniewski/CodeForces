//Death's Blesssing
//https://codeforces.com/contest/1749/problem/B
#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
using namespace std;
struct monster{
    int num;
    int health;
    int blessing;
    bool deleted=false;
    list<int>::iterator node;
};
int main(){
    int s;
    cin>>s;
    for(;s>0;s--){
        int monsterCount;
        cin>>monsterCount;
        monster monsters[monsterCount];
        list<int> linkedMonsters;
        long long time=0;
        for(int i=0; i<monsterCount; i++){
            cin>>monsters[i].health;
            monsters[i].num=i;
            time+=monsters[i].health;
        }
        for(int i=0; i<monsterCount; i++){
            cin>>monsters[i].blessing;
        }
        auto cmpBlessing = [](const monster& a, const monster& b){
            return a.blessing<b.blessing;
        };
        int cur=0;
        sort(monsters, monsters+monsterCount, cmpBlessing);
        for(int i=0; i<monsterCount; i++){
            linkedMonsters.push_back(monsters[i].num);
            monsters[i].node=--linkedMonsters.end();
        }
        auto cmpNum = [](const monster&a, const monster&b){
            return a.num<b.num;
        };
        sort(monsters,monsters+monsterCount,cmpNum);
        while(true){
            if(linkedMonsters.size()<=1){
                break;
            }
            int front=linkedMonsters.front();
            int back=linkedMonsters.back();
            while(monsters[cur].deleted) cur++;
            int min=monsters[cur].num;
            int whereMin=front;
            if(monsters[back].blessing<monsters[front].blessing) whereMin=back;
            if(monsters[min].blessing*2<monsters[whereMin].blessing) whereMin=min;
            monsters[whereMin].deleted=true;
            if(whereMin==front){
                time+=monsters[front].blessing;
                linkedMonsters.pop_front();
                continue;
            }
            if(whereMin==back){
                time+=monsters[back].blessing;
                linkedMonsters.pop_back();
                continue;
            }
            time+=2*monsters[min].blessing;
            linkedMonsters.erase(monsters[min].node);
        }
        cout<<time<<"\n";
    }
}