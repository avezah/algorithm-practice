#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 100;

struct Node{
    int x, y;
}node;

int n,m;
int matrix[MAXN][MAXN];
bool inq[MAXN][MAXN];
int X[4] = {0,0,1,-1};  //四个方向
int Y[4] = {1,-1,0,0};  //四个方向

bool judge(int x, int y){
    if(x>=n || y>=m || x<0 || y<0) return false;
    if(inq[x][y]==true || matrix[x][y]==0 ) return false;
    return true;
}

void BFS(int x, int y){
    queue<Node> Q;
    node.x = x;
    node.y = y;
    Q.push(node);
    inq[x][y] = true;
    while(!Q.empty()){
        Node pop = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int newx = pop.x + X[i];
            int newy = pop.y + Y[i];
            if(judge(newx, newy)){
                node.x = newx;
                node.y = newy;
                Q.push(node);
                inq[newx][newy] = true;
            }
        }
    }
}

int main(){
    freopen("in", "r", stdin);
    // in
    // 6 7
    // 0 1 1 1 0 0 1
    // 0 0 1 0 0 0 0
    // 0 0 0 0 1 0 0
    // 0 0 0 1 1 1 0
    // 1 1 1 0 1 0 0
    // 1 1 1 1 0 0 0
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        scanf("%d", &matrix[i][j]);
    
    int ans=0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(matrix[i][j] == 1 && inq[i][j] == false){
            ans++;
            BFS(i, j);
        }
    }
    printf("%d", ans);
    return 0;
}