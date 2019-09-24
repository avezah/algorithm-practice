# 1052 Linked List Sorting (25)

### Description
> A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer **key** and a **Next** pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

### Input Specification  
> Each input file contains one test case. For each case, the first line contains a positive N (<10^5) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by −1.   
> Then N lines follow, each describes a node in the format:
>  **Address Key Next**  
>  where **Address** is the address of the node in memory, **Key** is an integer in [−10^5, 10^5], and **Next** is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

### Output Specification
> For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

### Sample Input 
> 5 00001  
11111 100 -1  
00001 0 22222  
33333 100000 11111  
12345 -1 33333  
22222 1000 12345  

### Sample Output  
> 5 12345  
12345 -1 00001  
00001 0 11111  
11111 100 22222  
22222 1000 33333  
33333 100000 -1  

---

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