# 1005 Spell It Right (20)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336)

关键字：字符串、map

### 题意  
给出一个数字，计算各个位数总和。再用输出总和每一位的英文。  

💡 Tips：
- 这里使用了map，也许switch也可行
- 字符串和数字之间的相互转化

### 参考代码
```C++
#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, string> d;
    d.insert(pair<int, string>(0, "zero"));
    d.insert(pair<int, string>(1, "one"));
    d.insert(pair<int, string>(2, "two"));
    d.insert(pair<int, string>(3, "three"));
    d.insert(pair<int, string>(4, "four"));
    d.insert(pair<int, string>(5, "five"));
    d.insert(pair<int, string>(6, "six"));
    d.insert(pair<int, string>(7, "seven"));
    d.insert(pair<int, string>(8, "eight"));
    d.insert(pair<int, string>(9, "nine"));

    string num, sum_s;
    int sum = 0;
    cin>>num;
    for(int i = 0; i < num.size(); i++){
        sum += num[i]-'0';
    }
    sum_s = to_string(sum);
    for(int i = 0; i < sum_s.size(); i++){
        if(i == 0) cout<<d[sum_s[i]-'0'];
        else cout<<" "<<d[sum_s[i]-'0'];
    }
    cout<<endl;
    return 0;
}
```