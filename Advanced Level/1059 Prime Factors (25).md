# 1059 Prime Factors (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488)  

关键字：素数表

### 题意  
分解质因数

### 参考代码
```C++
#include<cstdio>
#include<cmath>

const int MAX = 100010;//sizeof(int) = 2*10^9; 10^5 > sqrt(2*10^9)

struct Factor
{
    int x;
    int cnt;
}fac[10];//最小的十个素数相乘大于int范围


int FindPrime(int prime[], int n){//构建素数表
    int pNum = 0;
    int p[n] = {0};
    for(int i = 2; i < n; i++)
        if(p[i] == false){
            prime[pNum++] = i;
            for(int j = i+i; j < n; j+=i)
                p[j] = true;
        }
    return pNum;
}

int main(){
    int prime[MAX];
    int pNum = FindPrime(prime, MAX);
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("1=1\n");
        return 0;
    }
    else printf("%d=", n);

    int sqr = (int)sqrt(1.0*n), num = 0;
    for(int i = 0; i < pNum && prime[i] < sqr; i++){//i小于素数总数且遍历的素数小于sqrt(n)
        if(n%prime[i] == 0){//找到素数因子
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while(n%prime[i] == 0){//计算素数因子个数
                n = n/prime[i];
                fac[num].cnt++;
            }
            num++;
        }
    }
    if(n != 1){//n不为1表示无法被小于n的素数乘积表示，此时n本身即为素数
        fac[num].x = n;
        fac[num].cnt = 1;
        num++;
    }
    for(int i = 0; i < num; i++){
        if(i>0) printf("*");
        printf("%d",fac[i].x);
        if(fac[i].cnt > 1) printf("^%d", fac[i].cnt);
    }
        
    return 0;
}
```