# 1006 Sign In and Sign Out (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928)

关键字：无

### 题意  
输出最早到的员工id和最迟走的员工id  
💡 Tips：  
- 可以直接时间按字符处理，字符字典序比较

### 参考代码
```C++
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 100000;

struct Person
{
    string id;
    int intime;
    int outtime;
}p[MAXN];

bool cmp_in(Person a, Person b){
    return  a.intime < b.intime;
}

bool cmp_out(Person a, Person b){
    return  a.outtime > b.outtime;
}

int main(){
    int n;
    string id;
    int a1,a2,a3,b1,b2,b3;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin>>id;
        scanf("%d:%d:%d %d:%d:%d",&a1,&a2,&a3,&b1,&b2,&b3);
        p[i].id = id;
        p[i].intime = a1*10000+a2*100+a3;
        p[i].outtime = b1*10000+b2*100+b3;
    }
    sort(p, p+n, cmp_in);
    cout<<p[0].id<<" ";
    sort(p, p+n, cmp_out);
    cout<<p[0].id<<endl;
    return 0;
}
```