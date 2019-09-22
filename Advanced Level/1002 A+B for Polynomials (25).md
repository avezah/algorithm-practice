# 1002 A+B for Polynomials (25)

![1002.png](https://i.loli.net/2019/09/19/DoT7cOlPpsM91YG.png)


---


**题意**  
合并多项式。  
K表示项数，N表示指数，a表示系数。  

**样例解释**  
2: 1.5  
1: 2.4+0.5=2.9  
0: 3.2  

**思路**  
1. 用`i`和`j`指针分别从左到右扫描两个多项式，`k`指针用于依次生成结果R
2. 比较两指针对应项的系数
3. 将系数大的项加入到R多项式，然后右移该项对应的指针以及`k`指针
4. 系数相同则指数不变，系数相加。如果系数相加结果`不为0`，则加入到R多项式，`ijk`指针右移。否则不加入， `ij`指针右移。
5. 当有指针移到多项式末尾，则另一指针所指项直接加入R多项式。直到该指针也移到末尾，退出循环。

---


**参考代码**
```C++
#include<cstdio>
#include<algorithm>
using namespace std;

struct NODE
{
    int exp;
    double coe;
}nodeA[20], nodeB[20], nodeR[20];


int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%lf", &nodeA[i].exp, &nodeA[i].coe);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%d%lf", &nodeB[i].exp, &nodeB[i].coe);

    int i = 0, j = 0, k = 0;
    while(i!=n || j!=m){
        if(j == m || nodeA[i].exp > nodeB[j].exp){
            nodeR[k].exp = nodeA[i].exp;
            nodeR[k].coe = nodeA[i].coe;
            k++;i++;
        }
        else if(i == n || nodeA[i].exp < nodeB[j].exp){
            nodeR[k].exp = nodeB[j].exp;
            nodeR[k].coe = nodeB[j].coe;
            k++;j++;
        }
        else{
            nodeR[k].exp = nodeA[i].exp;
            nodeR[k].coe = nodeA[i].coe + nodeB[j].coe;
            if(nodeR[k].coe != 0.0) k++; //crack point
            i++;j++;
        }
    }
    printf("%d", k);
    for(int i = 0; i < k; i++){
        printf(" %d %.1lf", nodeR[i].exp, nodeR[i].coe);
    }
    printf("\n");
}
```