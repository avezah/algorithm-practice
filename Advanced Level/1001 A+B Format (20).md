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