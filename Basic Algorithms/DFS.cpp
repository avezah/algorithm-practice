#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 10;
int n=9, k=3, x=15, maxSumSqu=-1, A[MAXN]={1,2,3,4,5,6,7,8,9};
vector<int> temp, ans;

void DFS(int index, int nowk, int sum, int sumSqu){
    if(nowk == k && sum == x){
        if(sumSqu > maxSumSqu){
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if(index == n || nowk > k || sum > x) return;
    temp.push_back(A[index]);
    DFS(index+1, nowk+1, sum+A[index], sumSqu+A[index]*A[index]);
    temp.pop_back();    //弹出已经dfs过的元素
    DFS(index+1, nowk, sum, sumSqu);
}

int main(){
    DFS(0, 0, 0, 0);
    printf("%d\n", maxSumSqu);
    for(vector<int>::iterator i = ans.begin(); i != ans.end(); i++) printf("%d ", *i);
    return 0;
}