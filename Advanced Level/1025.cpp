#include <cstdio> 
#include <stdio.h> 
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_TESTEE = 30010;

struct registration
{
    char number[15];
    int score;
    int location;
    int final_rank;
    int local_rank;
}testee[MAX_TESTEE];

bool cmp_local(registration A, registration B)
{
    if(A.location != B.location) return A.location < B.location;
    return A.score > B.score;
}

bool cmp_total(registration A, registration B)
{
    if(A.score != B.score) return A.score > B.score;
    return strcmp(A.number, B.number) < 0;
}

int main()
{
    int location, k, total = 0;
    scanf("%d", &location);
    for(int i = 0; i < location; i++)
    {
        scanf("%d", &k);
        getchar();
        char info[50];
        for(int j = total; j < total + k; j++)
        {
            fgets(info, 50, stdin);
            sscanf(info, "%s %d", testee[j].number, &testee[j].score); //attention &
            testee[j].location = i + 1;
        }
        total += k;
    }

    sort(testee, testee+total, cmp_local);
    int count = 0, local_now = 0;
    for(int i = 0; i < total; i++)
    {
        if(testee[i].location != local_now)
        {
            local_now = testee[i].location;
            testee[i].local_rank = 1;
            count = 2;
            continue;
        }
        if(testee[i].score < testee[i-1].score)
            testee[i].local_rank = count;////
        else
            testee[i].local_rank = testee[i-1].local_rank;
        count++;
    }

    sort(testee, testee+total, cmp_total);
    testee[0].final_rank = 1;
    for(int i = 1; i < total; i++)
    {
        if(testee[i].score < testee[i - 1].score)
            testee[i].final_rank = i + 1;
        else
            testee[i].final_rank = testee[i-1].final_rank;
    }
    printf("%d\n", total);
    for(int i = 0; i < total; i++)
    {
        printf("%s %d %d %d\n", testee[i].number, testee[i].final_rank ,testee[i].location, testee[i].local_rank);
    }
    
}