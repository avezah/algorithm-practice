# 1043 Is It a Binary Search Tree (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856)

关键字：BST、建树、先序遍历、后序遍历

### 题意  
1. 给出一串数字，判断是否是二叉查找树或者其镜像树的先序遍历。
2. 如果是，输出判断及其对应的后序遍历。

💡 Tips：
- 先建树，再获取所需的遍历序列

### 参考代码
```C++
#include<cstdio>
#include<vector>
using namespace std;

const int MAXN = 1010;

struct Node{
    int v;
    Node* left;
    Node* right;
    Node(){
        left = NULL;
        right = NULL;
    }
};

void insert(Node* &root, int v){
    if(root == NULL){
        root = new Node;
        root->v = v;
        return;
    }
    if(v < root->v) insert(root->left, v);
    else insert(root->right, v);
}

void preorder(Node* root, vector<int>&it){
    if(root == NULL) return;
    it.push_back(root->v);
    preorder(root->left, it);
    preorder(root->right, it);
}

void preorderMirror(Node* root, vector<int>&it){
    if(root == NULL) return;
    it.push_back(root->v);
    preorderMirror(root->right, it);
    preorderMirror(root->left, it);
}

void postorder(Node* root, vector<int>&it){
    if(root == NULL) return;
    postorder(root->left, it);
    postorder(root->right, it);
    it.push_back(root->v);
}

void postorderMirror(Node* root, vector<int>&it){
    if(root == NULL) return;
    postorderMirror(root->right, it);
    postorderMirror(root->left, it);
    it.push_back(root->v);
}

void print(vector<int> it){
    printf("YES\n");
    for(int i = 0; i < it.size(); i++){
        if(i == 0) printf("%d", it[i]);
        else printf(" %d", it[i]);
    }
    printf("\n");
}

int main(){
    int n, v;
    scanf("%d", &n);
    Node *root = NULL;
    vector<int> base;
    // 输入 保存原有数列 建树
    for(int i = 0; i < n; i++){
        scanf("%d", &v);
        base.push_back(v);
        insert(root, v);
    }
    vector<int> pre, preMirror, post;
    preorder(root, pre);
    preorderMirror(root, preMirror);
    //原数列是BST先序遍历，输出对应后序遍历
    if(pre == base){
        postorder(root, post);
        print(post);
    }
    //原数列是镜像BST先序遍历，输出对应后序遍历
    else if(preMirror == base){
        postorderMirror(root, post);
        print(post);
    }
    else printf("NO\n");
    
    return 0;
}
```