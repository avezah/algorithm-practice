# 1060 Are They Equal (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805413520719872)

关键字：string

### 题意  
在给定的精度和格式下输出浮点数并且比较是否相同
1. 删除前导0
2. 小数点界定数字小于0还是大于0
3. 小数点界定系数计算
4. 系数计算完毕后删除小数点并按照给定格式输出

### 参考代码
```C++
#include<iostream>
#include<string>
using namespace std;

string deal_str(string s, int &e, int n){
    while(s.length()>0 && s[0] == '0'){//删除前导0
        s.erase(s.begin());
    }
    if(s[0] == '.'){//num < 1
        s.erase(s.begin());
        while(s.length() > 0 && s[0] == '0'){//删除小数点后的连续0并且计算系数
            s.erase(s.begin());
            e--;
        }
    }
    else{//num > 1
        int k = 0;
        while(k<s.length() && s[k]!='.'){//计算系数
            k++;
            e++;
        }
        if(k<s.length()){//存在小数点
            s.erase(s.begin()+k);//删除小数点
        }
    }
    if(s.length() == 0){
        e = 0;
    }

    int num = 0;
    int k = 0;
    string res;
    while(num < n){//输出给定的长度
        if(k<s.length()) res+=s[k++];//如果还有数字
        else res+='0';//后续无数字则0补足
        num++;
    }
    return res;
}

int main(){
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int n, e1, e2 = 0;
    string num1, num2;
    while(cin >> n >> num1 >> num2){
        e1 = e2 = 0;
        string res1 = deal_str(num1, e1, n);
        string res2 = deal_str(num2, e2, n);
        if(res1 == res2 && e1 == e2){
            cout<<"YES 0."<<res1<<"*10^"<<e1<<endl;
        }
        else{
            cout<<"NO 0."<<res1<<"*10^"<<e1<<" 0."<<res2<<"*10^"<<e2<<endl;
        }
    }
    return 0;
}
```