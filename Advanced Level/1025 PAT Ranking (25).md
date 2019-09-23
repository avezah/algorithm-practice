# 1025 PAT Ranking (25)

### Description
> Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

### Input Specification
> Each input file contains one test case. For each case, the first line contains a positive number N (≤100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (≤300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

### Output Specification
> For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:  
> registration_number final_rank location_number local_rank

### Sample Input
> 2  
5  
1234567890001 95  
1234567890005 100  
1234567890003 95  
1234567890002 77  
1234567890004 85  
4  
1234567890013 65  
1234567890011 25  
1234567890014 100  
1234567890012 85  

### Sample Output
> 9  
1234567890005 1 1 1  
1234567890014 1 2 1  
1234567890001 3 1 2  
1234567890003 3 1 2  
1234567890004 5 1 4  
1234567890012 5 2 2  
1234567890002 7 1 5  
1234567890013 8 2 3  
1234567890011 9 2 4  


---


### 题意  
条件：  
- 考场数目N
- 考场考生数K
- 13位考生考号及考生成绩  

要求：输出`考生总人数`及排名信息`(考号|总排名|考场号|考场排名)`  

💡 Tips：
- 考场号从1开始，按照12345顺序依次记名
- 当考生成绩相同时**并列**那个名次且按照考号**小到大**顺序打印


### 样例解释 
无

### 思路  
本题本质是一道排序题，主要是解决考场排名和总排名的问题。  
1. 构建一个结构体`registration`存储考生信息(考号|分数|考场|总排名|考场排名)，按照题目要求记录考生信息并且统计考生总人数。
2. `cmp_local`排序规则结合`sort`函数对考生先按考场小到大排名，再按成绩高到低排。遍历计算考场排名，记录进考生信息。
3. `cmp_total`排序规则对考生按成绩高到低排名，再按考号小到大排名。遍历计算总排名，记录进考生信息。
4. 此时所有考生已经按照成绩从高到低排序，且考场排名正确，顺序遍历考生并且依次打印要求格式的结果。

---


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