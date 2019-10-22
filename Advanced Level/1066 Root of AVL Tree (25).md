# 1066 Root of AVL Tree (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805404939173888)

关键字：AVLTree、模板题

### 题意  
模拟AVL树插入，输出生成AVL树的根节点

### 参考代码
```C++
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
    int value, height;
    Node *lc, *rc;
    Node(int value){
        this->value = value;
        height = 1;
        lc = rc = NULL;
    }
};

int getHeight(Node *root){  //注意在root=NULL时返回0
    if(root == NULL) return 0;
    else return root->height;
}
int getBalanceFactor(Node *root){
    return (getHeight(root->lc) - getHeight(root->rc));
}
void updateHeight(Node *root){
    root->height = max(getHeight(root->lc), getHeight(root->rc))+1;
}
void rotateL(Node *&root){
    Node *temp = root->rc;
    root->rc = temp->lc;
    temp->lc = root;
    updateHeight(root); //先更新低位结点高度
    updateHeight(temp); //再更新高位结点高度 不可改变顺序
    root = temp;
}
void rotateR(Node *&root){
    Node *temp = root->lc;
    root->lc = temp->rc;
    temp->rc = root;
    updateHeight(root); //先更新低位结点高度
    updateHeight(temp); //再更新高位结点高度 不可改变顺序
    root = temp;
}
void insert(Node *&root, int value){
    if(root == NULL){
        root = new Node(value);
        return;
    }
    if(value < root->value){
        insert(root->lc, value);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->lc) == 1){    //LL
                rotateR(root);
            }else if(getBalanceFactor(root->lc) == -1){ //LR
                rotateL(root->lc);
                rotateR(root);
            }
        }
    }
    else{
        insert(root->rc, value);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rc) == -1){   //RR
                rotateL(root);
            }else if(getBalanceFactor(root->rc) == 1){  //RL
                rotateR(root->rc);
                rotateL(root);
            }
        }
    }
}

int main(){
    int num, n;
    scanf("%d", &n);
    Node *root = NULL;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        insert(root, num);
    }
    printf("%d\n", root->value);
    return 0;
}
```