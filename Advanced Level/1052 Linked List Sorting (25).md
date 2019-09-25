# 1052 Linked List Sorting (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805425780670464)

关键字：静态链表、排序

### 题意  
条件：
- 节点总数和首地址  
- 各个节点的地址、键值、下一节点地址  

要求打印排好序的节点列表  

💡 Tips：
- 注意边界情况当首地址节点为-1时，应该输出排好序的节点为0
- 其实题目要求的是打印由开始节点出发到结尾的所有节点排序，需要注意的是这个节点数可能会小于条件给出总结点数


### 参考代码
```C++
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX = 100010;

struct Node{
    int key;
    int next;
}node[MAX];

bool cmp(int A, int B){
    return node[A].key < node[B].key;
}

int main(){
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int n, begin, index;
    scanf("%d%d", &n, &begin);
    for(int i = 0; i < n; i++){
        scanf("%d", &index);
        scanf("%d%d", &node[index].key, &node[index].next);
    }
    if(begin == -1) {//如果开始地址是-1，则要求打印的序列不存在
        printf("0 -1\n");
        return 0;
    }
    n = 0;
    vector<int> addr;
    while(begin != -1){//统计从开始节点出发到结束(即下一节点地址为-1)的节点地址
        addr.push_back(begin);
        begin = node[begin].next;
        n++;
    }
    //以地址对应的节点键值对地址进行排序
    sort(addr.begin(), addr.begin()+n, cmp);
    printf("%d %05d\n", n, addr[0]);
    for(int i = 0; i < n; i++){
        if(i != n-1) printf("%05d %d %05d\n", addr[i], node[addr[i]].key, addr[i+1]);
        else printf("%05d %d -1\n", addr[n-1], node[addr[n-1]].key);
    }
    return 0;
}
```