# 1004 Counting Leaves (30)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184)

关键字：树

### 题意  
输出树的每一层叶子结点总数  
💡 Tips：
- 读懂题意，减少走弯路

### 参考代码
```C++
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 110;

int pathetic[MAXN], maxh = 0;

struct Node{
    int childn;
    int height;
    vector<int> child;
    Node(){
        this->childn = 0;
    }
}node[MAXN];

void addLevel(int id, int h){   //dfs给每个结点加上深度信息
    if(h > maxh) maxh = h;
    node[id].height = h;
    for(int i = 0; i < node[id].childn; i++) addLevel(node[id].child[i], h+1);
}

void cnt(int id){   //dfs遍历整棵树并且根据深度统计叶子结点
    if(node[id].childn == 0) 
    pathetic[node[id].height]++;
    for(int i = 0; i < node[id].childn; i++) cnt(node[id].child[i]);
}

int main(){
    int n, non_leaf, id, idn, idchild;
    scanf("%d%d", &n, &non_leaf);
    for(int i = 0; i < non_leaf; i++){
        scanf("%d%d", &id, &idn);
        node[id].childn = idn;
        for(int j = 0; j < idn; j++){
            scanf("%d", &idchild);
            node[id].child.push_back(idchild);
        }
    }
    memset(pathetic, 0, MAXN);
    addLevel(1, 0);
    cnt(1);
    for(int i = 0; i < maxh+1; i++){
        if(i == 0) printf("%d", pathetic[i]);
        else printf(" %d", pathetic[i]);
    }
    printf("\n");
    return 0;
}
```