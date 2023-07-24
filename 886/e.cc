#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        long long paintingCount, cardboard;
        cin>>paintingCount>>cardboard;
        double paintingSizes[paintingCount];
        double paint=0;
        double edgeSum=0;
        for(int i=0;i<paintingCount;i++){
            long long a;
            cin>>a;
            paint+=a*a;
            edgeSum+=a;
        }
        //cardboard=paint+edgeSum*4*w+paintingCount*4*(w*w);
        long long w1=(-4*edgeSum+sqrt((double)16*edgeSum*edgeSum-(16*paintingCount*(paint-cardboard))))/(8*paintingCount);
        if(w1>0) cout<<w1<<"\n";
        else{
            long long w2=(-4*edgeSum-sqrt((double)16*edgeSum*edgeSum-(16*paintingCount*(paint-cardboard))))/(8*paintingCount);
            cout<<w2<<"\n";
        }
    }
}