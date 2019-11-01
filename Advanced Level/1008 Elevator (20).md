# 1008 Elevator (20)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016)

关键字：无

### 题意  
电梯上升一层时间为6，下降一层时间为4，每层停留时间为5，初始在第0层，计算总时间

### 参考代码
```C++
#include<iostream>
using namespace std;

const int MAXN = 10010;
const int upt = 6;
const int downt = 4;
const int stayt = 5; 

int main(){
    int n;
    int *s = new int [MAXN];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>s[i];

    int t=s[0]*upt+stayt*n;
    for(int i = 1; i < n; i++){
        if(s[i]-s[i-1]>0) t+=(s[i]-s[i-1])*upt;
        else t+=(s[i-1]-s[i])*downt;
    }
    cout<<t<<endl;
    return 0;
}
```