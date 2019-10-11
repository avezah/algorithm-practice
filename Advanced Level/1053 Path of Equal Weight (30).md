# 1053 Path of Equal Weight (30)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512)

关键字：DFS、剪枝

### 题意  
1. 每个结点都包含权重数据域
2. 寻找从根结点到叶子结点权重加和等于期望的路径
3. 按照从大到小顺序输出所有路径

💡 Tips：
- 孩子结点数目不定，使用`vecor`容器存储
- 在输入时就对孩子结点按权重排序

### 参考代码
```C++
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 110;
int expect, w[MAXN];
vector<int> ans;

struct Node{
    int childn;
    vector<int> child;
}node[MAXN];

bool cmp(int a, int b){
    return w[a] > w[b];
}

void dfs(int id, int w_now){
    if(w_now == expect && node[id].childn == 0){    //权重达到期望并且为叶子结点
        for(int i = 0; i < ans.size(); i++){
            if(i == 0) printf("%d", ans[i]);
            else printf(" %d", ans[i]);
        }
        printf("\n");
        return;
    }
    if(w_now >= expect) return; //非叶子结点或者权重超过期望
    for(int i = 0; i < node[id].childn; i++){   //尝试每一个孩子结点
        int child_id = node[id].child[i];
        ans.push_back(w[child_id]);
        dfs(child_id, w_now+w[child_id]);   //计算重量并且继续查找
        ans.pop_back();                     //将结点弹出，尝试下一路径
    }
}

int main(){
    int n, not_leaf;
    scanf("%d%d%d", &n, &not_leaf, &expect);
    for(int i = 0; i < n; i++){
        node[i].childn = 0;
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < not_leaf; i++){
        int id, childn, child;
        scanf("%d%d", &id, &childn);
        node[id].childn = childn;
        for(int i = 0; i < childn; i++){
            scanf("%d", &child);
            node[id].child.push_back(child);
        }
        //将孩子结点按照权重大到小排序，方便直接按大到小输出
        sort(node[id].child.begin(), node[id].child.end(), cmp);
    }
    ans.push_back(w[0]);
    dfs(0, w[0]);

    return 0;
}
```