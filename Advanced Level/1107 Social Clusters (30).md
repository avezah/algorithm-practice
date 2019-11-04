# 1107 Social Clusters (30)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744)

关键字：并查集 模板题

### 题意  
要求找出具有相同兴趣的人群，输出集合个数及各个集合元素数  

💡 Tips：
- 注意isRoot使用整型来统计元素数目
- 要搞清楚合并的究竟是哪些元素、哪些元素是用来判断能否合并的
- 本题中合并的是人的编号、用兴趣爱好来判断是否合并

### 参考代码
```C++
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 1010;

//Template
vector<int> father, isRoot;
int findFather(int x){
    int a = x;
    while(x != father[x]){    //找到根结点
        x = father[x];
    }
    while(a!=father[a]){    //路径压缩
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;
}
//Template
bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, k, h, hobby[MAXN]={0}, cnt=0;
    scanf("%d", &n);
    father.resize(n+1); //resize方法让vector的内容存在
    isRoot.resize(n+1, 0);
    for(int i = 1; i <= n; i++) father[i] = i;   //题目要求编号为1-n 
    for(int i = 1; i <= n; i++){
        scanf("%d:", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &h);
            if(hobby[h] == 0) hobby[h] = i;
            Union(i, findFather(hobby[h]));
        }
    }
    for(int i = 1; i <= n; i++){    //统计各个集合的元素数目
        isRoot[findFather(i)]++;
    }
    for(int i = 1; i <= n; i++){    //统计集合数目
        if(isRoot[i] != 0) cnt++;
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp);    //大到小排序
    for(int i = 0; i < cnt; i++){               //输出cnt个即可
        if(i == 0) printf("%d", isRoot[i]);
        else printf(" %d", isRoot[i]);
    }
    return 0;
}
```