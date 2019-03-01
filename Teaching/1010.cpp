#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;
#define N 10
char maze[N][N];
int n,m,step;
int sx,sy;
int ex,ey;
bool flag;
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};
bool vis[N][N];

inline int Manhattan(int x1,int y1,int x2,int y2){ return abs(x1 - x2) + abs(y1 - y2); }//坐标上的两点，轴线最短距离

void dfs(int curx , int cury , int curstep){
    if(flag) //如果已经找到可行路径，剩下的递归进程全部终止
        return;

    if(curx == ex && cury == ey && curstep == step){ //找到可行路径
        flag = true;
        return;
    }

    if(Manhattan(curx , cury , ex , ey) > step - curstep) //如果当前点到终点的曼哈顿距离大于剩余距离，则不可能到达终点.
        return;

    for(int j = 0;j != 4;j++){
        int nx = dx[j] + curx;
        int ny = dy[j] + cury;
        int nstep = curstep + 1;//找出下一状态
        if(nstep > step
            || nx < 0 || nx >= n || ny < 0 || ny >= m
            || maze[nx][ny] == 'X'
            || vis[nx][ny]){
            continue;
         }//检测下一状态是否合法
        vis[nx][ny] = true;//进行访问标记
        dfs(nx , ny , nstep);//访问下一状态
        vis[nx][ny] = false;//进行回溯
    }

}
int main(){
    while(~scanf("%d%d%d",&n,&m,&step) && (n + m + step)){
        for(int j = 0;j != n;j++){
            scanf("%s" , maze[j]);
        }
        for(int j = 0;j != n;j++){
            for(int k = 0;k != m;k++){
                if(maze[j][k] == 'S')
                    sx = j , sy = k;
                if(maze[j][k] == 'D')
                    ex = j , ey = k;
             }
        }//找到起始状态和终止状态

        flag = false;
        memset(vis , 0 , sizeof(vis));
        vis[sx][sy] = true;

        if(Manhattan(sx , sy , ex , ey) % 2 != step % 2){
            ;
        }else{
            dfs(sx , sy , 0);
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
