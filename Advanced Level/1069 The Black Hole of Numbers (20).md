# 1069 The Black Hole of Numbers (20)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088)

关键字：字符串

### 题意  
1. 给出一个四位数
2. 将四位数的各个数字从大到小排序得到数字A
3. 从小到大排序得到数字B
4. 计算C=A-B，如果C=6147或0000则结束，否则到2

💡 Tips：
- 当初始给出的数为6147应当不作任何处理和输出

### 参考代码
```C++
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX = 4;

bool cmp(int a, int b){
    return a > b;
}

void num2array(int num, int array[]){
    for(int i = 0; i < MAX; i++){
        array[i] = num%10;
        num /= 10;
    }
}

void array2num(int &num, int array[]){
    num = 0;
    for(int i = 0; i < MAX; i++){
        num = num*10 + array[i];
    }
}

int main(){
    int num, array[MAX];
    scanf("%d", &num);
    int res = 1;
    while(res != 6174 && res){      //当num=6147或者为0时退出
        num2array(num, array);      //转为数组
        sort(array, array+MAX, cmp);//大到小排序
        array2num(res, array);      //导出数字
        sort(array, array+MAX);     //小到大排序
        array2num(num, array);      //导出数字
        printf("%04d - %04d = %04d\n", res, num, res-num);
        res -= num;
        num = res;
    }

    return 0;
}
```