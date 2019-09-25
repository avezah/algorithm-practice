# 1093 Count PAT's (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805373582557184)

关键字：TwoPointers，递推

### 题意  
计算给出字符串中尽可能多地PAT组合数量，例如：
- PPAT：2
- PPPAATT: 12

💡 Tips：
- 每个A左侧的P的数量乘以A右侧T的数量即为这个A可能组成的所有PAT总数
- 利用递推公式求左侧P的数量(或右侧T的数量)

### 参考代码
```C++
#include<cstdio>
#include<cstring>
const int MAX = 100010;
const int MOD = 1000000007;

int main(){
    char s[MAX];
    scanf("%s", s);
    int len = strlen(s);

    int p[MAX];//字符串对应位置左侧的'P'的数量
    memset(p, 0, MAX);
    if(s[0] != 'P') p[0] = 0;
    else p[0] = 1;
    for(int i = 1; s[i] != '\0'; i++){//利用递推公式计算s[i]及其左侧的'P'的总数
        if(s[i] == 'P') p[i] = p[i-1] + 1;  //若s[i]是P则s[i]左侧的p的数量是s[i-1]左侧p的数量加1
        else p[i] = p[i-1];
    }
    // for(int i = 0; i < len; i++) printf("%d", p[i]);
    // printf("\n");

    int n = 0;
    int t[MAX];//字符串对应位置左侧的'T'的数量
    memset(t, 0, MAX);
    if(s[len-1] == 'T') t[len-1] = 1;
    else t[len-1] = 0;
    for(int i = len-2; i >= 0; i--){//利用递推公式计算s[i]及其右侧的'T'的总数
        if(s[i] == 'T') t[i] = t[i+1] + 1;
        else t[i] = t[i+1];
        if(s[i] == 'A') n = (n+t[i]*p[i])%MOD;//如果是'A'，则统计'PAT'总数
    }
    // for(int i = len-1; i >= 0; i--) printf("%d", t[i]);
    // printf("\n");
    printf("%d\n", n);
    return 0;
}
```