#include <stdio.h>
#include <iostream>
#include <cctype>

using namespace std;
#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3f

#define MM(X) memset(X , 0x00 , sizeof(X))
#define MZ(X) memset(X , 0XFF , sizeof(X))
#define MI(X) memset(X , 0x3f , sizeof(X))

#define ISPATH(X) (X == '.')
#define ISWALL(X) (X == '*')
#define ISSTART(X) (X == '@')
#define ISEND(X) (X == '^')
#define ISDOOR(X) (X >= 'A' && X <= 'J')
#define ISKEY(X) (X >= 'a' && X <= 'j')

#define HASHKEY(KEY) (1 << ((KEY) - 'a')) //字符key的hash值,二进制值 
#define BITGET(HASH_VALUE , KEY) (HASH_VALUE & HASHKEY(KEY) == HASHKEY(KEY)) //当前的hash值(二进制值)是否包含字符key 
#define BITSET(HASH_VALUE , KEY) (HASH_VALUE | HASHKEY(KEY)) //返回一个拥有字符key的hash值 

int n,m,max_count;
char maze[25][25];
int dis[1 << 10][25][25]; //钥匙的状态 , x坐标 , y坐标 
const int dx[] = {0 , 0 , 1 , -1};
const int dy[] = {1 , -1 , 0 , 0};
int sx,sy;
int ex,ey;
struct Node{
	int key,x,y;
	Node(int _key,int _x,int _y){
		key = _key;
		x = _x;
		y = _y;
	}
};
void bfs(){
	MI(dis); //设置成最大值
	queue<Node> Q;
	Q.push(Node( 0 , sx , sy));
	dis[0][sx][sy] = 0;
	while(!Q.empty()){
		Node cur = Q.front();
		Q.pop();
		for(int j = 0;j != 4;j++){
			int nx = cur.x + dx[j];
			int ny = cur.y + dy[j];
			int nkey = cur.key;
			if(nx < 0 || n <= nx || ny < 0 || m <= ny){ //判单越界 
				continue;
			}
			if(ISWALL(maze[nx][ny])){
				continue;
			}
			if(ISDOOR(maze[nx][ny]) && !BITGET(cur.key , tolower(maze[nx][ny]))){
				continue;
			}
			if(ISKEY(maze[nx][ny])){
				nkey = BITSET(nkey , maze[nx][ny]);
			}
			if(dis[nkey][nx][ny] != INF){
				continue;
			}
			dis[nkey][nx][ny] = dis[cur.key][cur.nx][cur.y];
			Q.push(Node(nkey , nx, ny));
		}
	}
}



int main(){
	test(); 
	while(~scanf("%d%d%d",&n,&m,&max_count)){
		for(int j = 0;j != n;j++){
			for(int k = 0;k != m;k++){
				do{
					maze[j][k] = getchar();
				}while(maze[j][k] == ' ' || maze[j][k] == '\n');
			}
		}
		
		for(int j = 0;j != n;j++){
			for(int k = 0;k != m;k++){
				if(ISSTART(maze[j][k])){
					sx = j;
					sy = k;
				}
				if(ISEND(maze[j][k])){
					ex = j;
					ey = k;
				}
			}
		}
		
		bfs();
	}
}
