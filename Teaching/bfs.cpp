#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define oil '@'
#define land '*'
#define N 105
int visit[N][N]; //这个地方我是否走过
char matrix[N][N]; //存储字符矩阵
int n,m;

int judge(int x,int y){
    if(x < 0)
        return 0;
    if(y < 0)
        return 0;
    if(x >= n)
        return 0;
    if(y >= m)
        return 0;
    return 1;
}
const int dx[8] = {-1 , -1 , -1 , +1 , +1 , +1 , +0 , +0};
const int dy[8] = {-1 , +0 , +1 , -1 , +0 , +1 , -1 , +1};
//把和x,y所有联通的地方全变成搜索过的状态
struct Node{
    Node(int _x,int _y):x(_x),y(_y){}
    int x,y;
};
void bfs(int x,int y){
    std::queue<Node> Q;
    visit[x][y] = 1;
    Q.push(Node(x , y));
    while(!Q.empty()){
        Node cur = Q.front();
        Q.pop();
        for(int j = 0;j != 8;j++){
            int nx = cur.x + dx[j];
            int ny = cur.y + dy[j];
            if(judge(nx , ny) && matrix[nx][ny] == oil && !visit[nx][ny]){
                visit[nx][ny] = 1;
                Q.push(Node(nx , ny));
            }
        }
    }
}

int main(){
    while(~scanf("%d%d",&n,&m) && (n || m)){
        memset(visit , 0 , sizeof(visit));
        for(int j = 0;j != n;j++)
            scanf("%s",matrix[j]);
        int ans = 0;
        for(int j = 0;j != n;j++){
            for(int k = 0;k != m;k++){
                if(matrix[j][k] == oil && !visit[j][k])
                    bfs(j , k) , ans ++;
                visit[j][k] = 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
