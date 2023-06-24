//The Lakes
//https://codeforces.com/contest/1829/problem/E
#include <iostream>
#include <queue>
using namespace std;
struct cell{
    int depth;
    int color=0;
};
struct pos{
    int x;
    int y;
};
int BFS(pos start, cell** grid, int rows, int columns){
    if(grid[start.x][start.y].color!=0 || grid[start.x][start.y].depth==0) return 0;
    int volume=0;
    queue<pos> que;
    que.push(start);
    //wasted so much time on a typo xdd
    while(!que.empty()){
        pos cur = que.front();
        que.pop();
        if(grid[cur.x][cur.y].color==2 || grid[cur.x][cur.y].depth==0) continue;
        grid[cur.x][cur.y].color=2;
        volume+=grid[cur.x][cur.y].depth;
        if( cur.x+1<rows && grid[cur.x+1][cur.y].color==0){
            que.push({cur.x+1, cur.y});
            grid[cur.x+1][cur.y].color=1;
        }
        if( cur.y+1<columns && grid[cur.x][cur.y+1].color==0){
            que.push({cur.x, cur.y+1});
            grid[cur.x][cur.y+1].color=1;
        }
        if( cur.x-1>=0 && grid[cur.x-1][cur.y].color==0){
            que.push({cur.x-1, cur.y});
            grid[cur.x-1][cur.y].color=1;
        }
        if( cur.y-1>=0 && grid[cur.x][cur.y-1].color==0){
            que.push({cur.x, cur.y-1});
            grid[cur.x][cur.y-1].color=1;
        }
    }
    return volume;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin>>s;
    for(;s>0;s--){
        int rows, columns;
        cin>>rows>>columns;
        cell** grid=new cell*[rows];
        for(int i=0; i<rows; i++){
            grid[i]= new cell[columns];
            for(int j=0; j<columns; j++){
                cin>>grid[i][j].depth;
            }
        }
        int maxVolume=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                int volume=BFS({i,j}, grid, rows, columns);
                if(volume>maxVolume) maxVolume=volume;
            }
        }
        cout<<maxVolume<<"\n";
        for(int i=0; i<rows; i++){
            delete [] grid[i];
        }
        delete [] grid;
    }
}