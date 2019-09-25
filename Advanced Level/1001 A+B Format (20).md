# 1001 A+B Format (20)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400)

关键字：无

### 题意  
输出标准格式的计算结果，即从右往左每三个数字用逗号隔开

### 参考代码
```C++
#include<cstdio>
#include<cstring>
const int MAX = 1000010;

int main()
{
    int a, b, c;
    scanf("%d%d", &a,&b);
    c = a + b;
    if(c < 0){
        printf("-");
        c = -c;
    }

    char result[MAX];
    sprintf(result, "%d\0", c);
    int len = strlen(result);
    for(int i = 0; result[i] != '\0'; i++){
        //从前往后扫描，当未扫描数的数字个数为3的倍数且不为0时，额外输出一个逗号
        if((len-i-1)%3 == 0&&i != len-1) printf("%c,", result[i]);
        else printf("%c", result[i]);
    }
}
```