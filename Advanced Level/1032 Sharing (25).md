# 1032 Sharing (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920)

关键字：静态链表

### 题意  
找到公共子串的开始节点

### 参考代码
```C++
#include<cstdio>
using namespace std;

const int MAX = 100010;

struct Node{//静态链表存储节点
    char c;
    int next;
    bool flag;
}node[MAX];

int main(){
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int a,b,n;
    scanf("%d%d%d", &a, &b, &n);
    int here, next;
    char temp;
    for(int i = 0; i < n; i++){
        scanf("%d %c %d", &here, &temp, &next);
        node[here].c = temp;
        node[here].next = next;
        node[here].flag = false;
    }
    int res = -1;
    while(a != -1){//标记链表所有节点
        node[a].flag = true;
        a = node[a].next;
    }
    while(b != -1){
        if(node[b].flag == true){//遇到已经标记的节点则公共部分开始
            res = b;
            break;
        }
        b = node[b].next;
    }
    
    if(res == -1) printf("-1\n");//如果res不变则表示没有公共部分
    else printf("%05d", res);
    return 0;
}
```