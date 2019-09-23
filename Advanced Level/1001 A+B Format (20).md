# 1001 A+B Format (20)

### Description
> Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

### Input Specification  
> Each input file contains one test case. Each case contains a pair of integers a and b where −10^6 ≤a,b≤ 10^6. The numbers are separated by a space.

### Output Specification
> For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

### Sample Input 
> -1000000 9

### Sample Output  
> -999,991

---

### 题意  
输出标准格式的计算结果，即从右往左每三个数字用逗号隔开

### 样例解释 
-1000000 + 9 = -999991

### 思路 
1. 计算两个数的得到加和结果
2. 如果结果是正数，则不处理，否则直接输出负号并取相反数为正数
3. 从左往右扫描，当剩下的数的个数为3的倍数时，输出当前数字并且输出一个逗号，否则仅仅输出当前数字

---


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