# 1007 Maximum Subsequence Sum (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168)

关键字：最大和子序列

### 题意  
输出所给数字序列里最大和子序列的和及开始结尾数字  

💡 Tips：
- 题目要求输出的最大和子序列的和及开始结尾数字，而非索引
- 每次将数字加入Sum中并检查Sum如下，这样可以保证得到最大和子序列
   - 如果Sum大于maxSum，则更新maxSum
   - 如果Sum为负数则使Sum归零

### 参考代码
```C++
/*
testCase1：
4
-2 0 0 -1
[output] 0 0 0
*/
#include<iostream>
using namespace std;

const int MAXN = 10010;


int main(){
    // freopen("in", "r", stdin);
    int n;
    int *num = new int[MAXN];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>num[i];

    bool allNegtive = true;
    int nowBegin = num[0], maxBegin = num[0], maxEnd = num[0];
    int nowSum = 0, maxSum = -1;
    for(int i = 0; i < n; i++){
        if(num[i] >= 0) allNegtive = false;
        nowSum += num[i];
        if(nowSum > maxSum){
            maxSum = nowSum;
            maxEnd = num[i];
            maxBegin = nowBegin;
        }
        else if(nowSum < 0){
            nowSum = 0;
            nowBegin = num[i+1];
        }
    }
    if(allNegtive){
        maxSum = 0;
        maxBegin = num[0];
        maxEnd = num[n-1];
    }
    if(n!=0) cout<<maxSum<<" "<<maxBegin<<" "<<maxEnd<<endl;
    return 0;
}
```