# 1025 PAT Ranking (25)

[@PTA](https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872)

关键字：排序

### 题意  
条件：  
- 考场数目N
- 考场考生数K
- 13位考生考号及考生成绩  

要求：输出`考生总人数`及排名信息`(考号|总排名|考场号|考场排名)`  

💡 Tips：
- 考场号从1开始，按照12345顺序依次记名
- 当考生成绩相同时**并列**那个名次且按照考号**小到大**顺序打印

### 参考代码
```C++
#include <cstdio> 
#include <stdio.h> 
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_TESTEE = 30010;

//记录考生信息
struct registration
{
    char number[15];
    int score;
    int location;
    int final_rank;
    int local_rank;
}testee[MAX_TESTEE];

//考场排名规则：考场号小的在前，考场号相同则成绩高的在前
bool cmp_local(registration A, registration B){
    if(A.location != B.location) return A.location < B.location;
    return A.score > B.score;
}

//总排名规则：成绩高的在前，成绩相同则考号小的在前
bool cmp_total(registration A, registration B){
    if(A.score != B.score) return A.score > B.score;
    return strcmp(A.number, B.number) < 0;
}

int main()
{
    int location, k, total = 0;
    scanf("%d", &location);
    for(int i = 0; i < location; i++){
        scanf("%d", &k);
        getchar();
        char info[50];
        for(int j = total; j < total + k; j++){
            fgets(info, 50, stdin);
            sscanf(info, "%s %d", testee[j].number, &testee[j].score); //注意加上 &
            testee[j].location = i + 1;
        }
        total += k;
    }
    //排出考生所在的考场排名
    sort(testee, testee+total, cmp_local);
    int count = 0, local_now = 0;
    for(int i = 0; i < total; i++){
        if(testee[i].location != local_now){//排到下一考场
            local_now = testee[i].location;
            testee[i].local_rank = 1;
            count = 2;
            continue;
        }
        if(testee[i].score < testee[i-1].score)
            testee[i].local_rank = count;
        else
            testee[i].local_rank = testee[i-1].local_rank;
        count++;
    }
    //排出考生总排名
    sort(testee, testee+total, cmp_total);
    testee[0].final_rank = 1;
    for(int i = 1; i < total; i++){
        if(testee[i].score < testee[i - 1].score)
            testee[i].final_rank = i + 1;
        else
            testee[i].final_rank = testee[i-1].final_rank;
    }
    printf("%d\n", total);
    for(int i = 0; i < total; i++){
        printf("%s %d %d %d\n", testee[i].number, testee[i].final_rank ,testee[i].location, testee[i].local_rank);
    }
}
```