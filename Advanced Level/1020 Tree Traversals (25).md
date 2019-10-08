# 1020 Tree Traversals (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072)

关键字：后续遍历、中序遍历、层次遍历、中序后序建树

### 题意  
给出树的节点个数、后序遍历序列和中序遍历序列，要求输出层次遍历序列

### 参考代码
```C++
#include<cstdio>
#include<cstring>

const int MAXN = 35;

int n, post[MAXN], in[MAXN], tree[MAXN*MAXN];

void buildTree(int pL, int pR, int iL, int iR, int index){
    if(pL > pR) return; //左边界大于右边界，查找结束
    int index_root;
    for(int i = iL; i <= iR; i++){  //遍历中序序列，找到根节点位置
        if(in[i] == post[pR]){
            tree[index] = in[i];    //将找到的根节点存入数组表示的完全二叉树
            index_root = i;
            break;
        }
    }
    //左子树节点数为index_root-iL
    //后序序列的左子树部分为[pL, pL+(index_root-iL)-1]
    //中序序列的左子树部分为[iL, index_root-1]
    buildTree(pL, pL+(index_root-iL)-1, iL, index_root-1, index*2); //完全二叉树左子树下标index*2
    //后序序列的右子树部分为[pL+(index_root-iL), pR-1]
    //中序序列的右子树部分为[index_root+1, iR]
    buildTree(pL+(index_root-iL), pR-1, index_root+1, iR, index*2+1);   //完全二叉树右子树下标index*2+1
}

int main(){
    // freopen("in", "r", stdin);

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    memset(tree, 0, sizeof(tree));
    buildTree(0, n-1, 0, n-1, 1);   //完全二叉树根节点下标必须为1
    for(int i = 1; i < MAXN*MAXN; i++){
        if(i == 1) printf("%d", tree[i]);
        else if(tree[i] != 0) printf(" %d", tree[i]);
    }
    printf("\n");

    return 0;
}
```